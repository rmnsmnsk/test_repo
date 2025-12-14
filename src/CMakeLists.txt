cmake_minimum_required(VERSION 3.25)
project(12_2_c C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(main 12.2_c/12.c 12.2_c/float_rep.c)
add_executable(run_test tests/test_12.c 12.2_c/float_rep.c)

enable_testing()
add_test(NAME BasicTests COMMAND test)