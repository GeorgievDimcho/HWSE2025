cmake_minimum_required(VERSION 3.00)
project(project_name C)
set(CMAKE_C_CSTANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread -lm -Wall -Werror -Wpedantic -Wextra")
include_directories(./inc)
file(GLOB MAIN
    "src/main.c"
    "src/help.c" 
    )
add_executable(run_me ${MAIN})