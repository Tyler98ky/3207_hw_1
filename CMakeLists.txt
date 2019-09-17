cmake_minimum_required(VERSION 3.14)
project(3207_hw_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(3207_hw_1 main.c main.h Config.c Config.h PriorityQueue.c PriorityQueue.h)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)