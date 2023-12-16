//
// Created by andrea on 15/12/23.
//
#include "gtest/gtest.h"
#include "/home/andrea/CLionProjects/Elaborato_Prog/GoogleTest/lib/googletest-1.14.0/googlemock/include/gmock/gmock.h"
#include "../Timer.h"


TEST(TimerTest, SetInitialTime){ // Test per vedere se in settaggio del timer avviene correttamente
    Timer timer;
    timer.setInitialTime(01,20,45);

    EXPECT_EQ(timer.remainingHours,01);
    EXPECT_EQ(timer.remainingMinutes,20);
    EXPECT_EQ(timer.remainingSeconds,45);
}

TEST(TimerTest, StartAndTimeout){ // Test per controllare se alla fine del tempo il timer
    Timer timer;                  // lancia il messaggio 'TIMEOUT!'
    timer.start();
    //aggiungi '00:00:05' nella finestra di dialogo

    for(int i = 0; i <= 5; i++){
        timer.updateTimer();
    }

    EXPECT_EQ(timer.displayLabel->text(), "TIMEOUT!");
}

TEST(TimerTest, UpdateTimer){// Test per vedere se il timer si aggiorna correttamente
    Timer timer;
    timer.start();
    //aggiungi '00:01:15' nella finestra di dialogo

    for(int i = 0; i < 30; i++){
        timer.updateTimer();
    }


    EXPECT_EQ(timer.displayLabel->text(), "00:00:45");
}