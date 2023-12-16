//
// Created by andrea on 05/12/23.
//

#include "Date.h"

void Date::set(int d, int m, int y) {  //classse che rappresenta la data
    day = d;
    month = m;
    year = y;
}

QString Date::display() const {
    return QString("%1%2%3").arg(day, 2, 10, QChar('0'))
                                .arg(month,2, 10, QChar('0'))
                                .arg(year);
}
