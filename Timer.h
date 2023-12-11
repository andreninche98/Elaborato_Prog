//
// Created by andrea on 05/12/23.
//

#ifndef ELABORATO_PROG_TIMER_H
#define ELABORATO_PROG_TIMER_H
#include "QObject"
#include "QDateTime"

class Timer : public QObject{
    Q_OBJECT
private:
    QDateTime start_time;
public:
    Q_INVOKABLE void start();
    Q_INVOKABLE int elapsed_seconds() ;

};


#endif //ELABORATO_PROG_TIMER_H
