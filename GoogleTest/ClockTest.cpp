//
// Created by andrea on 15/12/23.
//
#include "gtest/gtest.h"
#include "../Clock.h"
#include "QThread"

TEST(ClockTest, Update){ //Test per vedere se la data corrente è giusta e sel'orologio si aggiorna
    Clock clock;
    clock.start();

    QDate currentDate = QDate::currentDate();

    QThread::sleep(2);
    clock.update();
    QString displayText = clock.getClockDisplay()->text();
    ASSERT_FALSE(displayText.isEmpty());
    EXPECT_TRUE(displayText.contains(QString::number(currentDate.year())));
    EXPECT_TRUE(displayText.contains(QString::number(currentDate.month())));
    EXPECT_TRUE(displayText.contains(QString::number(currentDate.day())));

}