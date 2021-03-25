/// Author- Deepson Khadka
///Testing Generator class using Google Test

#include <gtest/gtest.h>
#include "../src/parser.h"


Parser<double> fixtureLoadsWithTime = Parser<double>("../data/system_load_mw.csv");

///data for hard coding
Parser<double> fixtureLoadsNoTime = Parser<double>("../data/load_mw_no_time.csv");

///Testing column size
TEST(parser_Test, test_ColumnSize_LoadWithTime){

    EXPECT_EQ(2, fixtureLoadsWithTime.getCol());
}

///Testing row size
TEST(parser_Test, test_RowSize_LoadWithTime){
    EXPECT_EQ(288, fixtureLoadsWithTime.getRow());
}

///Testing column size
TEST(parser_Test, test_ColumnSize_LoadWithoutTime){

    EXPECT_EQ(289, fixtureLoadsNoTime.getCol());
}

///Testing row size
TEST(parser_Test, test_RowSize_LoadWithoutTime){
    EXPECT_EQ(1, fixtureLoadsNoTime.getRow());
}