cmake_minimum_required(VERSION 3.16)

# Project configuration
project(MyMathFunction)

# Default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Enable test option
option(ENABLE_TESTS "Enable building and running tests" OFF)

# Define paths
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/Src")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/Inc")

# Verify that source and header files exist
file(GLOB SOURCES "${SOURCE_DIR}/my_math_function.c")
file(GLOB HEADERS "${INCLUDE_DIR}/my_math_function.h")

# Debug: Print source and header files
message("Source files: ${SOURCES}")
message("Header files: ${HEADERS}")

# Check if the source file exists
if(NOT SOURCES)
    message(FATAL_ERROR "Source file 'my_math_function.c' not found in ${SOURCE_DIR}")
endif()

# Create the main executable
add_library(MY_MATH_FUNCTION ${SOURCES})

# Create the executable
add_executable(math_program ${SOURCE_DIR}/main.c)
target_link_libraries(math_program PRIVATE MY_MATH_FUNCTION)

# Include directories for headers
target_include_directories(MY_MATH_FUNCTION PUBLIC ${INCLUDE_DIR})

# Include tests if enabled
if(ENABLE_TESTS)
    message("Tests are enabled. Adding test directory.")
    add_subdirectory(tests)
else()
    message("Tests are disabled. Building only the main application.")
endif()
