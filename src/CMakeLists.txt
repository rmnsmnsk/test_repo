cmake_minimum_required(VERSION 3.25)

project(braces C)

add_library(stack stack/STR.c)

add_executable(braces braces.c)

target_link_libraries(braces PRIVATE stack)