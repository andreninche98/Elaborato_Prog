//
// Created by andrea on 05/12/23.
//

#include "Timer.h"

void Timer::start() {
    start_time = QDateTime::currentDateTime();
}

int Timer::elapsed_seconds() {
    QDateTime now = QDateTime::currentDateTime();
    qint64 elapsed = start_time.msecsTo(now)/1000;
    return static_cast<int>(elapsed);
}