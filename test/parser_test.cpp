// Author Deepson Khadka
//UnitTests Parser class units
#include <gtest/gtest.h>
#include "../src/parser.h"
#include <iostream>

//data with no time
Parser<unsigned int> loadParser_no_Time = Parser<unsigned int>("../load_mw_no_time.csv");
//data with time
Parser<unsigned int> loadParser_Time = Parser<unsigned int>("../system_load_mw.csv");

///Test fails if File is empty or null
TEST(parserTest, ReadTest1) {
EXPECT_FALSE(loadParser_no_Time.getRow()<=0||loadParser_no_Time.getCol()<=0);
}

///Test fails if File is empty or null
TEST(parserTest, ReadTest2) {
    EXPECT_FALSE(loadParser_Time.getRow()<=0||loadParser_Time.getCol()<=0);
}
///File missing or Error handling test
TEST(parserTest,  FileNotFoundException){
        EXPECT_ANY_THROW("FileNotFoundException");
}

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
