#include <gtest/gtest.h>
#include "../src/parser.h"

Parser fixture = Parser("../data/system_load_mw.csv");

//Testing matrix column size
TEST(parser_Test1, test_ColumnSize){

    EXPECT_EQ(2,fixture.getCol());
}

//Testing matrix row size
TEST(parser_Test2, test_RowSize){
    EXPECT_EQ(289,fixture.getRow());
}

