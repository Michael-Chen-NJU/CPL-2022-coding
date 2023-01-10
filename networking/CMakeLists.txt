cmake_minimum_required(VERSION 3.24)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c)
add_executable(uc-sever uc-sever.c basic/networking.c)
add_executable(uc-client uc-client.c basic/networking.c)


