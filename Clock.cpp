//
// Created by andrea on 12/12/23.
//

#include "QDebug"
#include "Clock.h"

Clock::Clock(QObject*parent) : QObject(parent), clockWindow(nullptr) {  //classe che implementa l'orologio
    currentDate = new Date(this,1,1,1);  //inizializzata a 1/1/1 per superare i controlli su Date
    currentTime = new Time(this,0,0,0);
    connect(&timer, &QTimer::timeout, this, &Clock::update);
}

void Clock::start() {
    if(!clockWindow){
        clockWindow = new QWidget;
        clockWindow->setWindowTitle("Clock App");
        clockWindow->resize(300,300);

        layout = new QVBoxLayout(clockWindow);
        clockDisplay = new QLabel("", clockWindow);
        exitButton = new QPushButton("Exit", clockWindow);

        layout->addWidget(clockDisplay);
        layout->addWidget(exitButton);

        connect(exitButton, &QPushButton::clicked, this, &Clock::exitClock);

        clockWindow->show();
        clockWindow->setAttribute(Qt::WA_DeleteOnClose);

        timer.start(1000);
    }
}

void Clock::update() {
    if(currentDate && currentTime) {
        currentDate->set(QDate::currentDate().year(),QDate::currentDate().month(),QDate::currentDate().day());
        currentTime->set(QTime::currentTime().hour(),QTime::currentTime().minute(),QTime::currentTime().second());

        QString displayString = currentDate->display() + " " + currentTime->display();
        clockDisplay->setText(displayString);
    }
}
void Clock::exitClock() {
    clockWindow->close();
}

QLabel *Clock::getClockDisplay() const {
    return clockDisplay;
}
