cmake_minimum_required(VERSION 3.25)

project(Dijkstra C)


add_library(stack stack/STR.c)

add_executable(dj dj.c)

target_link_libraries(dj PRIVATE stack)