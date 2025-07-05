cmake_minimum_required(VERSION 3.27)
project(SudokuSolverPRNG)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Recursively collect all .cpp and .c files from src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.c
)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Create the executable
add_executable(SudokuSolverPRNG ${SOURCES} ${HEADERS})
