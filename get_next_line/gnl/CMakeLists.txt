cmake_minimum_required(VERSION 3.12)
project(get_next_line C)

set(CMAKE_C_STANDARD 99)

set(HEADERS get_next_line.h)
set(SOURCES main.c get_next_line.c get_next_line_utils.c test_get_next_line.c)

add_executable(get_next_line ${HEADERS} ${SOURCES})