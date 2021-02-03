cmake_minimum_required(VERSION 3.16)
project(unit_commitment)
set(CMAKE_CXX_STANDARD 11)
add_executable(unit_commitment main.cpp generator.h matrix.h parser.h ranking.h parser.cpp matrix.cpp generator.cpp ranking.cpp)