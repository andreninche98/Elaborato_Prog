//
// Created by andrea on 05/12/23.
//

#ifndef ELABORATO_PROG_TIME_H
#define ELABORATO_PROG_TIME_H

#include <QObject>
#include <QString>



class Time : public QObject{  //Classe che rappresenta il tempo
    Q_OBJECT

public:
    Time(QObject *parent, int hours, int minutes, int seconds);
    void set(int h, int m, int s);
    QString display() const;
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    void decreaseSecond();
private:
    int hours;
    int minutes;
    int seconds;
};


#endif //ELABORATO_PROG_TIME_H
