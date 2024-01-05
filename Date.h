//
// Created by andrea on 05/12/23.
//

#ifndef ELABORATO_PROG_DATE_H
#define ELABORATO_PROG_DATE_H
#include <QObject>
#include <QString>


class Date : public QObject {  //classe che rappresenta la data
    Q_OBJECT

public:
    Date(QObject *parent, int year, int month, int day);
    void set (int y, int m, int d);
    QString display() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;

private:
    int day;
    int month;
    int year;
    bool followsGregorianCalendar() const;
    int daysInMonth(int year, int month);
};



#endif //ELABORATO_PROG_DATE_H
