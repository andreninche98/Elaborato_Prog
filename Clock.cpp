//
// Created by andrea on 12/12/23.
//

#include "Clock.h"

Clock::Clock() :currentDateTime(QDateTime::currentDateTime()) {}

QString Clock::display() const {
    return currentDateTime.toString("yyyy-MM-dd HH:mm:ss");
}

void Clock::update() {
    currentDateTime= QDateTime::currentDateTime();
}