cmake_minimum_required(VERSION 3.23)
project(So_Long C)

set(CMAKE_C_STANDARD 99)

add_executable(so_long src/so_long.c inc/so_long.h Get_Next_line/get_next_line.c src/sl_checks_util.c)
