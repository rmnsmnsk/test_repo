cmake_minimum_required(VERSION 3.25)

project(staples C)

add_library(stack stack/STR.c)

add_executable(staples staples.c)

target_link_libraries(staples PRIVATE stack)