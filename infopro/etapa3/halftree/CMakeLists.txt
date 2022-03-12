cmake_minimum_required(VERSION 3.19)
project(halftree)

set(CMAKE_CXX_STANDARD 11)

file(COPY adat.be DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(halftree
        main.cpp)
