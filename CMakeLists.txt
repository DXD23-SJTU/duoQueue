cmake_minimum_required(VERSION 3.8)
project(simulatorQueue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp simulator.h simulator.cpp linkQueue.h)
add_executable(simulatorQueue ${SOURCE_FILES})