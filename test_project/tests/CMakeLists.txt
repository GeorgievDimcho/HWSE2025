cmake_minimum_required(VERSION 3.00)
project(project_name C)
set(CMAKE_C_CSTANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread -lm -Wall -Werror -Wpedantic -Wextra")
include_directories(./Unity-2.6.1/src)
include_directories(../inc)
file(GLOB MAIN
    "../src/help.c" 
    "test.c"
    "./Unity-2.6.1/src/unity.c"
    )
add_executable(tests_exec ${MAIN})