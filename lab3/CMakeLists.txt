cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(main LANGUAGES C)
set(CMAKE_C_FLAGS "-pthread")
add_executable(main ./src/main.c)