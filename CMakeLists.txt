cmake_minimum_required(VERSION 3.21)
project(logingit)

set(CMAKE_CXX_STANDARD 23)

add_executable(logingit main.cpp loginSystem.cpp loginSystem.h)
