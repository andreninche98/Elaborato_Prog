//
// Created by andrea on 12/12/23.
//

#include "Clock.h"

Clock::Clock(QObject*parent) : QObject(parent), clockWindow(nullptr) {  //classe che implementa l'orologio
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
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString displayString = currentDateTime.toString("yyyy-MM-dd HH:mm:ss");
    clockDisplay->setText(displayString);
}
void Clock::exitClock() {
    clockWindow->close();
}