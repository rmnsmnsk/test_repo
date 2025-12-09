cmake_minimum_required(VERSION 3.25)

project(Dijkstra C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(stack)

add_executable(dj dj.c)

target_link_libraries(dj PRIVATE stack)