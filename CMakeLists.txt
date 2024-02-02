cmake_minimum_required(VERSION 3.27)
project(arrays C)

set(CMAKE_C_STANDARD 11)

include_directories(src/operations)

add_executable(arrays main.c)