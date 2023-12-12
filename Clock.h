//
// Created by andrea on 12/12/23.
//

#ifndef ELABORATO_PROG_CLOCK_H
#define ELABORATO_PROG_CLOCK_H

#include "QString"
#include "QDateTime"

class Clock {
public:
    Clock();
    QString display() const;
    void update();
private:
    QDateTime currentDateTime;

};


#endif //ELABORATO_PROG_CLOCK_H
