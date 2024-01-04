//
// Created by andrea on 15/12/23.
//
#include "gtest/gtest.h"
#include "/home/andrea/CLionProjects/Elaborato_Prog/GoogleTest/lib/googletest-1.14.0/googlemock/include/gmock/gmock.h"
#include "../Timer.h"
#include "QDebug"


TEST(TimerTest, SetInitialTime){ // GoogleTest per vedere se in settaggio del timer avviene correttamente
    Timer timer(nullptr);
    timer.setInitialTime(01,20,45);

    EXPECT_EQ(timer.getRemainingTime()->getHours(),01);
    EXPECT_EQ(timer.getRemainingTime()->getMinutes(),20);
    EXPECT_EQ(timer.getRemainingTime()->getSeconds(),45);
}

TEST(TimerTest, StartAndTimeout){ // GoogleTest per controllare se alla fine del tempo il timer lancia il messaggio 'TIMEOUT!'
    Timer timer(nullptr);
    timer.setInitialTime(0,0,5);
    timer.start();


    for(int i = 0; i <= 5; i++){
        timer.updateTimer();
    }
    QString expectedLabelText = "TIMEOUT!";
    QString actualLabelText = timer.getDisplayLabelText();

    qDebug() << "Expected Label Text:" << expectedLabelText;
    qDebug() << "Actual Label Text:" << actualLabelText;

    ASSERT_EQ(actualLabelText,expectedLabelText);


}

TEST(TimerTest, UpdateTimer){ // GoogleTest per vedere se il timer si aggiorna correttamente
    Timer timer(nullptr);
    timer.setInitialTime(0,1,15);
    timer.start();

    for(int i = 0; i < 30; i++){
        timer.updateTimer();
    }
    EXPECT_EQ(timer.getDisplayLabelText(), "00:00:45");
}