cmake_minimum_required(VERSION 3.25)
project(infix_converter)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(stack STATIC
    stack/STR.c
)

add_executable(to_postfix
    to_postfix.c
)
target_link_libraries(to_postfix stack)