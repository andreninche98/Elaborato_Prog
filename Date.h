//
// Created by andrea on 05/12/23.
//

#ifndef ELABORATO_PROG_DATE_H
#define ELABORATO_PROG_DATE_H
#include <QObject>
#include <QString>


class Date : public QObject {
    Q_OBJECT

public:
    int day;
    int month;
    int year;

    void set (int d, int m, int y);
    QString display() const;

};


#endif //ELABORATO_PROG_DATE_H
