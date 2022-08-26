cmake_minimum_required(VERSION 3.0)

set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

project(pong VERSION 1.0)

add_executable(pong Main.cpp)

set(EXECUTABLE_OUTPUT_PATH ../bin)