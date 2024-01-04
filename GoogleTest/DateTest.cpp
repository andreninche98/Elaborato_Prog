//
// Created by andrea on 04/01/24.
//
#include "gtest/gtest.h"
#include "../Date.h"

TEST(DateTest, PossibleDate){
    Date date(nullptr, 2023, 10, 20);

    EXPECT_EQ(date.getYear(),2023);
    EXPECT_EQ(date.getMonth(),10);
    EXPECT_EQ(date.getDay(),20);
}

TEST(DateTest, ImpossibleYear){
    Date date(nullptr,-2023,9,20);

    EXPECT_EQ(date.getYear(),0);
    EXPECT_EQ(date.getMonth(),0);
    EXPECT_EQ(date.getDay(),0);
}

TEST(DateTest, ImpossibleMonth){
    Date date(nullptr,2023,13,20);

    EXPECT_EQ(date.getYear(),0);
    EXPECT_EQ(date.getMonth(),0);
    EXPECT_EQ(date.getDay(),0);
}

TEST(DateTest, ImpossibleDay){
    Date date(nullptr,2023,11,40);

    EXPECT_EQ(date.getYear(),0);
    EXPECT_EQ(date.getMonth(),0);
    EXPECT_EQ(date.getDay(),0);
}