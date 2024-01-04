//
// Created by andrea on 05/12/23.
//

#include "Date.h"   //classe che rappresenta la data

Date::Date(QObject *parent, int year, int month, int day) : QObject(parent) {
    if(year >= 0 && year <= 9999){
        if(month >= 1 && month <= 12){
            if(day >= 1 && day <= daysInMonth(year,month)){
                if(followsGregorianCalendar()) {
                    this->year = year;
                    this->month = month;
                    this->day = day;
                }
            }
        }
    }
}

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
    if(year > 1582){
        return true;
    } else if (year == 1582){
        if(month > 10){
            return true;
        } else if(month == 10){
            return day >= 15;
        }
    }
    return false;
}

int Date::daysInMonth(int year, int month) {
    if( year && month){
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31,30,31 ,30,31};
        if((year % 4 == 0 && year %100 != 0) || (year % 400 == 0)){
            daysInMonth[1] = 29;
        }
        return daysInMonth[month];
    } else {
        return -1;
    }
}

