#include <unistd.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    int fd[2];
    fd[0] = std::stoi(argv[0]);
    fd[1] = std::stoi(argv[1]);

    int file = std::stoi(argv[2]);
    if (dup2(file, 0) == -1) {
        std::cerr << "dub error\n";
        return -1;
    }

    float x, sum = 0;
    char c;
    do {
        std::cin >> x;
        sum += x;
        c = getchar();
        if (c == '\n') {
            write(fd[1], &c, sizeof(c));
            write(fd[1], &sum, sizeof(sum));
            sum = 0;
        }
    } while(c != EOF);
    write(fd[1], &c, sizeof(c));

    close(fd[1]);
    close(fd[0]);

    return 0;
}
