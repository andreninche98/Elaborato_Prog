//
// Created by andrea on 05/12/23.
//

#ifndef ELABORATO_PROG_TIME_H
#define ELABORATO_PROG_TIME_H

#include "QObject"
#include "QString"



class Time : public QObject{
    Q_OBJECT

public:
    int hours;
    int minutes;
    int seconds;

    void set(int h, int m, int s);
    QString display() const;

};


#endif //ELABORATO_PROG_TIME_H
