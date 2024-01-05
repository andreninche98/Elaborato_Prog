//
// Created by andrea on 04/01/24.
//
#include "gtest/gtest.h"
#include "../Date.h"

TEST(DateTest, PossibleDate){
    Date Pdate(nullptr, 2023, 10, 20);

    EXPECT_EQ(Pdate.getYear(),2023);
    EXPECT_EQ(Pdate.getMonth(),10);
    EXPECT_EQ(Pdate.getDay(),20);
}

TEST(DateTest, ImpossibleMonth){
    EXPECT_THROW({
        try {
            Date date(nullptr,2023,14,20);
        } catch (const std::invalid_argument& e){
            EXPECT_STREQ(e.what(),"Mese non valido");
            throw ;
        }
    }, std::invalid_argument);
}

TEST(DateTest, ImpossibleDay) {
    EXPECT_THROW({
        try {
            Date date(nullptr, 2023, 11, 40);
        } catch (const std::invalid_argument &e) {
            EXPECT_STREQ(e.what(), "Giorno non valido");
            throw;
        }
        }, std::invalid_argument);
}

TEST(DateTest, ImpossibleYear){
    EXPECT_THROW({
        try {
            Date date(nullptr, -2023, 11, 10);
        } catch (const std::invalid_argument &e) {
            EXPECT_STREQ(e.what(), "Anno non valido");
            throw;
        }
        }, std::invalid_argument);
}

TEST(DateTest, LeapYear){
    EXPECT_THROW({
        try{
            Date date(nullptr,2022,2,29);
        } catch (const std::invalid_argument &e){
            EXPECT_STREQ(e.what(), "Giorno non valido");
            throw ;
        }
    }, std::invalid_argument);

    Date date2(nullptr,2020,2,29);

    EXPECT_EQ(date2.getYear(),2020);
    EXPECT_EQ(date2.getMonth(),2);
    EXPECT_EQ(date2.getDay(),29);
}