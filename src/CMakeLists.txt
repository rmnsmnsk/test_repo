cmake_minimum_required(VERSION 3.10)
project(7_c_program C)

set(CMAKE_C_STANDARD 11)

add_executable(7_c_program main/7_c_program.c main/functions.c)

enable_testing()
add_test(NAME Tests COMMAND 7_c_program --test)