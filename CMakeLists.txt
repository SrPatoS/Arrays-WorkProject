cmake_minimum_required(VERSION 3.27)
project(untitled C)

set(CMAKE_C_STANDARD 11)

include_directories(src/operations)

add_executable(untitled main.c
        src/operations/addOperation/addOperation.h
        src/operations/addOperation/addOperation.c)
