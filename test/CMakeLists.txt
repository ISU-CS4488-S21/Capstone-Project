cmake_minimum_required(VERSION 3.16)
project(Capstone-Project)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest)



include_directories(lib/googletest/googletest/include)


add_executable(Capstone-Project testGenerator.cpp ../src/generator.cpp ../src/generator.h ../src/economic_dispatch.h ../src/economic_dispatch.cpp testEconomic_Dispatch.cpp parser_test.cpp ../src/parser.h test_Combination.cpp test_DP.cpp)
target_link_libraries(Capstone-Project gtest gtest_main)