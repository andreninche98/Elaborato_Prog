//
// Created by andrea on 05/12/23.
//

#include "Time.h"
#include "QDebug"  //classe che implementa il tempo

Time::Time(QObject *parent, int hours, int minutes, int seconds) : QObject(parent) {
    if(hours >= 0 && hours < 24){
        if(minutes >= 0 && minutes < 60 ){
            if(seconds >= 0 && seconds < 60){
                this->hours = hours;
                this->minutes = minutes;
                this->seconds = seconds;
            }
        }
    }
}

void Time::set(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
}

int Time::getHours() const {
    return hours;
}

int Time::getMinutes() const {
    return minutes;
}

int Time::getSeconds() const {
    return seconds;
}

QString Time::display() const {
    qDebug() << "Display - hours:" << hours << "minutes:" << minutes << "seconds:" << seconds;
    return QString("%1:%2:%3").arg(hours, 2, 10, QChar('0'))
                                  .arg(minutes, 2, 10, QChar('0'))
                                  .arg(seconds, 2, 10, QChar('0'));

}


void Time::decreaseSecond() {
    if (seconds > 0) {
        seconds--;
    } else {
        if (minutes > 0) {
            minutes--;
            seconds = 59;
        } else {
            if (hours > 0) {
                hours--;
                minutes = 59;
                seconds = 59;
            }
        }
    }
}

