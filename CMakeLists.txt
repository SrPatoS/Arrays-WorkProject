cmake_minimum_required(VERSION 3.27)
project(arrays C)

set(CMAKE_C_STANDARD 11)

include_directories(src/operations)

add_executable(arrays main.c
        src/operations/addOperation/addOperation.h
        src/operations/addOperation/addOperation.c
        src/operations/subtractOperation/subtractOperation.h
        src/operations/subtractOperation/subtractOperation.c
        src/arrays/arrays.h
        src/arrays/arrays.c
        src/printArray/printArray.h
        src/printArray/printArray.c)
