cmake_minimum_required(VERSION 4.2)
project(cp3_atm_projeto C)

set(CMAKE_C_STANDARD 11)

add_executable(cp3_atm_projeto src/main.c
        src/util.c
        include/util.h)
