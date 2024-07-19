# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(Snipper VERSION 1.0)

# Set the C standard to C99
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable target from the snipper.c file
add_executable(snipper src/snipper.cpp)

