cmake_minimum_required(VERSION 3.16)
project(unit_commitment)
set(CMAKE_CXX_STANDARD 11)
add_executable(unit_commitment src/main.cpp src/generator.h src/matrix.h src/parser.h src/ranking.h src/parser.cpp src/matrix.cpp src/generator.cpp src/ranking.cpp)