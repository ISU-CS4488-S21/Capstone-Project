//
// Created by Deepson Khadka on 5/4/21.
//

#include <gtest/gtest.h>
#include "../src/parser.h"

//data with no time
Parser<unsigned int> loadParser_no_Time = Parser<unsigned int>("../load_mw_no_time.csv");
//data with time
Parser<unsigned int> loadParser_Time = Parser<unsigned int>("../system_load_mw.csv");

///Testing column size of load_mw_no_time.csv data
TEST(parserTest,  getColTest_no_Time){
EXPECT_EQ(289,loadParser_no_Time.getCol());
}

///Testing row size of load_mw_no_time.csv data
TEST(parserTest,  getRowTest_no_Time){
    EXPECT_EQ(1,loadParser_no_Time.getRow());
}

///Testing column size of load_mw_Time.csv data
TEST(parserTest,  getColTest_Time){
    EXPECT_EQ(2,loadParser_Time.getCol());
}

///Testing row size of load_mw_Time.csv data
TEST(parserTest,  getRowTest_Time){
    EXPECT_EQ(288,loadParser_Time.getRow());
}