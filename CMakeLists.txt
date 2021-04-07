cmake_minimum_required(VERSION 3.16)
project(unit_commitment)
set(CMAKE_CXX_STANDARD 11)

file(GLOB DATAFILES "${CMAKE_CURRENT_SOURCE_DIR}/data/*.csv")
file(COPY ${DATAFILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

include_directories("${PROJECT_SOURCE_DIR}/src/")
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(unit_commitment "${PROJECT_SOURCE_DIR}/src/main.cpp" ${SOURCES} src/combination.h)