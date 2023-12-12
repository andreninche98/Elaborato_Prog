//
// Created by andrea on 05/12/23.
//

#ifndef ELABORATO_PROG_TIMER_H
#define ELABORATO_PROG_TIMER_H
#include "QDateTime"

class Timer {
private:
    QDateTime start_time;
public:
    Timer();
    void start();
    void update();
    int elapsed_seconds() ;

};


#endif //ELABORATO_PROG_TIMER_H
