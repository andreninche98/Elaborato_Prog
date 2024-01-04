//
// Created by andrea on 16/12/23.
//
#include "gtest/gtest.h"

#include "../Chrono.h"

TEST(ChronoTest, StartAndPause){ //Test per controllare il funzionamento del cronometro con start e pausa
    Chrono chrono;
    EXPECT_FALSE(chrono.getIsRunning());
    chrono.start();

    chrono.startPauseChrono();
    EXPECT_TRUE(chrono.getIsRunning());
    EXPECT_FALSE(chrono.getIsPaused());

    chrono.startPauseChrono();
    EXPECT_FALSE(chrono.getIsRunning());
    EXPECT_TRUE(chrono.getIsPaused());
}

TEST(ChronoTest, Reset) { //Test per vedere se il cronometro viene effettivamente resettato
    Chrono chrono;
    chrono.start();
    chrono.resetChrono();

    EXPECT_FALSE(chrono.getIsRunning());
    EXPECT_FALSE(chrono.getIsPaused());

    EXPECT_EQ(chrono.displayTime, "00:00,00");
}

TEST(ChronoTest, Exit) { //Test per controllare che il cronometro sia effettivamente spento
    Chrono chrono;       // infatti non è nè in esecuzione nèin pausa
    chrono.start();
    chrono.exitChrono();

    ASSERT_FALSE(chrono.getIsRunning());
    ASSERT_FALSE(chrono.getIsPaused());
}