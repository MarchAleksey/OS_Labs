#include <iostream>
#include <unistd.h>
#include "../include/messages.hpp"
#include <chrono>

class Timer {
public:
    void start() {
        m_startTime = std::chrono::high_resolution_clock::now();
        m_running = true;
    }

    void stop() {
        m_endTime = std::chrono::high_resolution_clock::now();
        m_running = false;
    }

    double time() {
        std::chrono::time_point<std::chrono::high_resolution_clock> endTime;

        if (m_running) {
            endTime = std::chrono::high_resolution_clock::now();
        } else {
            endTime = m_endTime;
        }

        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_startTime).count();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_endTime;
    bool m_running = false;
};

int main(int argc, char const *argv[])
{
    Timer timer;
    int curId = atoi(argv[1]), childId = -1;
    bool hasChild = false, flag = true;
    zmq::context_t parentCtx;
    zmq::socket_t parentSock(parentCtx, zmq::socket_type::pair);
    parentSock.connect(("tcp://127.0.0.1:" + std::to_string(PORT + curId)).c_str());
    zmq::context_t nodeCtx;
    zmq::socket_t nodeSock;
    std::cout << "OK: " << getpid() << std::endl;
    while (flag) {
        nlohmann::json reply = Recv(parentSock);
        nlohmann::json request;
        request["ans"] = "error";
        request["type"] = reply["type"];
        request["id"] = reply["id"];
        if (reply["type"] == "ping") {
            if (reply["id"] == curId) {
                request["ans"] = "ok";
            } else if (hasChild) {
                nlohmann::json downRequest = reply;
                nlohmann::json downReply = sendAndRecv(downRequest, nodeSock, 0);
                if (downReply["ans"] == "ok") {
                    request = downReply;
                }
            }
        } else if (reply["type"] == "create") {
            if (reply["parentId"] == curId) {
                if (!hasChild) {
                    int i = reply["id"];
                    initSock(nodeCtx, nodeSock);
                    nodeSock.bind(("tcp://*:" + std::to_string(PORT + i)).c_str());
                    pid_t pid = fork();
                    if (pid == 0) {
                        execl("./calculation", "./calculation", std::to_string(i).c_str(), nullptr);
                        return 0;
                    } else {
                        if (!hasChild) {
                            childId = reply["id"];
                            hasChild = true;
                            request["ans"] = "ok";
                        } else {
                            destroySock(nodeCtx, nodeSock);
                        }
                    }
                }
            } else if (hasChild) {
                nlohmann::json downRequest = reply;
                nlohmann::json downReply = sendAndRecv(downRequest, nodeSock, 0);
                if (downReply["ans"] == "ok") {
                    request = downReply;
                }
            }
        } else if (reply["type"] == "remove") {
            if (reply["id"] == curId) {
                if (!hasChild) {
                    flag = false;
                    request["ans"] = "ok";
                }
            } else if (reply["id"] == childId) {
                hasChild = false;
                request["ans"] = "ok";
                nlohmann::json downRequest = reply;
                nlohmann::json downReply = sendAndRecv(downRequest, nodeSock, 0);
                if (downReply["ans"] == "ok") {
                    request = downReply;
                    request["ans"] = "ok";
                    request["parentId"] = curId;
                    destroySock(nodeCtx, nodeSock);
                }
            } else {
                nlohmann::json downRequest = reply;
                nlohmann::json downReply = sendAndRecv(downRequest, nodeSock, 0);
                if (downReply["ans"] == "ok") {
                    request = downReply;
                }
            }
        } else if (reply["type"] == "exec") {
            if (reply["id"] == curId) {
                if (reply["command"] == "start") {
                    timer.start();
                    std::cout << "Ok:" << reply["id"] << std::endl;
                    request["ans"] = "ok";
                } else if (reply["command"] == "time") {
                    std::cout << "Ok:" << reply["id"] << ":" << timer.time() << std::endl;
                    request["ans"] = "ok";
                } else if (reply["command"] == "stop") {
                    timer.stop();
                    std::cout << "Ok:" << reply["id"] << std::endl;
                    request["ans"] = "ok";
                } else {
                    request["ans"] = "error";
                }
            } else {
                nlohmann::json downRequest = reply;
                nlohmann::json downReply = sendAndRecv(downRequest, nodeSock, 0);
                if (downReply["ans"] == "ok") {
                    request = downReply;
                }
            }
        }
        Send(request, parentSock);
    }
    parentSock.disconnect(("tcp://127.0.0.1:" + std::to_string(PORT + curId)).c_str());
    destroySock(parentCtx, parentSock);
    destroySock(nodeCtx, nodeSock);
    return 0;
}
