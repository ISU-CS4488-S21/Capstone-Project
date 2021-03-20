cmake_minimum_required(VERSION 3.16)
project(Capstone-Project)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)
add_executable(Capstone-Project ../src/generator.cpp ../src/generator.h test_matrix.cpp test_generator.cpp)
target_link_libraries(Capstone-Project gtest gtest_main)