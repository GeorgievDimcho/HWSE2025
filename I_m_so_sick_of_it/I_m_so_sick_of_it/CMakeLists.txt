cmake_minimum_required(VERSION 3.10)
project(BoschCarManagementSystem C)

option(COVERAGE "Enable coverage reporting" ON)

add_compile_options(-Wall -Wextra -fprofile-arcs -ftest-coverage)

if(COVERAGE)
    message(STATUS "Building with coverage flags")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

# Header-Verzeichnisse
include_directories(
    inc/data
    inc/logic
    inc/presentation
    vendor/Unity/src
    vendor/CMock/src
    mocks
)

# Bibliothek aus src-Dateien
add_library(car_management STATIC
    src/data/file_handling.c
    src/logic/student.c
    src/presentation/display_stuff.c
)

target_include_directories(car_management PUBLIC inc)

# Testquellen
set(TEST_SOURCES
    mocks/Mockdisplay_stuff.c
    mocks/Mockfile_handling.c
    vendor/Unity/src/unity.c
    vendor/CMock/src/cmock.c
    test/test_main.c
)

# Test-Executable
add_executable(unit_tests ${TEST_SOURCES})
target_link_libraries(unit_tests car_management)

# Tests aktivieren
enable_testing()
add_test(NAME UnitTests COMMAND unit_tests)

# Coverage
add_custom_target(coverage
    COMMAND gcovr --root .. --object-directory . --filter '../src/' --html --html-details -o coverage.html
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
