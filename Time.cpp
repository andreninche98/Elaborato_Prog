//
// Created by andrea on 05/12/23.
//

#include "Time.h"
#include "QDebug"

void Time::set(int h, int m, int s) {  //classe che implementa il tempo
    hours = h;
    minutes = m;
    seconds = s;
}
QString Time::display() const {
    qDebug() << "Display - hours:" << hours << "minutes:" << minutes << "seconds:" << seconds;
    return QString("%1:%2:%3").arg(hours, 2, 10, QChar('0'))
                                  .arg(minutes, 2, 10, QChar('0'))
                                  .arg(seconds, 2, 10, QChar('0'));

}
