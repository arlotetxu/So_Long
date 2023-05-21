cmake_minimum_required(VERSION 3.23)
project(So_Long C)

set(CMAKE_C_STANDARD 99)

add_executable(so_long src/so_long.c inc/so_long.h Get_Next_line/get_next_line.c Get_Next_line/get_next_line.h
        Get_Next_line/get_next_line_utils.c src/sl_checks_util.c src/sl_exit.c src/sl_ckecks_util_2.c src/sl_utils.c)
