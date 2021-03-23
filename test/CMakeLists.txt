cmake_minimum_required(VERSION 3.16)
project(Capstone-Project)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)
add_executable(Capstone-Project ../src/Generator.cpp ../src/Generator.h ../src/economic_dispatch.h ../src/economic_dispatch.cpp ../src/dijkstra.cpp test_generator.cpp test_Economic_Dispatch.cpp  test_Dijkstra.cpp test_parser.cpp)
target_link_libraries(Capstone-Project gtest gtest_main)