//
// Created by andrea on 04/01/24.
//
#include "gtest/gtest.h"
#include "../Time.h"

TEST(TimeTest, ImpossibleTime){
    Time validTime(nullptr,12,30,40);

    EXPECT_THROW(Time invalidHourTime(nullptr, 25, 15, 30), std::invalid_argument);
    EXPECT_THROW(Time invalidMinuteTime(nullptr, 10, 75, 20), std::invalid_argument);
    EXPECT_THROW(Time invalidSecondTime(nullptr, 8, 45, 80), std::invalid_argument);

    EXPECT_EQ(validTime.getHours(), 12);
    EXPECT_EQ(validTime.getMinutes(), 30);
    EXPECT_EQ(validTime.getSeconds(), 40);
}