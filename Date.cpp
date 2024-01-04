//
// Created by andrea on 05/12/23.
//

#include "Date.h"   //classe che rappresenta la data

Date::Date(QObject *parent, int year, int month, int day) : QObject(parent), year(year), month(month), day(day) {}

void Date::set(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}

QString Date::display() const {
    return QString("%1/%2/%3").arg(year, 2, 10, QChar('0'))
                                .arg(month,2, 10, QChar('0'))
                                .arg(day,2,10,QChar('0'));
}
int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}
bool Date::followsGregorianCalendar() const {
    return year > 1582 || (year == 1582 && month > 10 || month == 10 && day >= 15);
}

