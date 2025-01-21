cmake_minimum_required(VERSION 3.16)

# Enable code coverage
option(COVERAGE "Enable code coverage" ON)
#set(CPPUTEST_HOME "${CMAKE_SOURCE_DIR}/tools/cpputest")
find_package(CppUTest REQUIRED)
# Enable coverage flags
if(COVERAGE)
    message("Building with coverage reporting")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

# Include directories
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/Src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Inc")
include_directories(${SOURCE_DIR} ${INCLUDE_DIR})

# Collect source and header files
file(GLOB SRC_FILES ${SOURCE_DIR}/*.c)
file(GLOB INC_FILES ${INCLUDE_DIR}/*.h)

# Exclude specific files
list(FILTER SRC_FILES EXCLUDE REGEX ".*main.c")
#list(FILTER SRC_FILES EXCLUDE REGEX ".*sysmem.c")
#list(FILTER SRC_FILES EXCLUDE REGEX ".*system_stm32f1xx.c")

# Collect test files
file(GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# Combine all source and test files
set(TEST_SOURCES ${SRC_FILES} ${TEST_FILES})

# Define the test executable
add_executable(MyMathTest ${TEST_SOURCES})

# Link with CppUTest
target_include_directories(MyMathTest PRIVATE ${CPPUTEST_HOME}/include)
#target_link_libraries(MyMathTest PRIVATE ${CPPUTEST_HOME}/lib/libCppUTest.a)
target_link_libraries(MyMathTest PRIVATE CppUTest CppUTestExt)
# Set output directory for the test executable
set_target_properties(MyMathTest PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
)

# Enable testing
enable_testing()
add_test(NAME MyMathTest COMMAND MyMathTest)