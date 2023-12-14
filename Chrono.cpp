//
// Created by andrea on 05/12/23.
//

#include "Chrono.h"
#include <QDebug>

Chrono::Chrono(QObject *parent) : QObject(parent), chronoWindow(nullptr), elapsed(0), isRunning(false), isPaused(false){
    connect(&chrono, &QTimer::timeout, this, &Chrono::update);
}

void Chrono::start() {
    if(!chronoWindow){
        chronoWindow = new QWidget;
        chronoWindow->setWindowTitle("Chrono App");
        chronoWindow->resize(300,300);

        layout = new QVBoxLayout(chronoWindow);
        chronoDisplay = new QLabel("00:00,00", chronoWindow);
        startPauseButton = new QPushButton("Start", chronoWindow);
        resetButton = new QPushButton("Reset", chronoWindow);
        exitButton = new QPushButton("Exit", chronoWindow);

        layout->addWidget(chronoDisplay);
        layout->addWidget(startPauseButton);
        layout->addWidget(resetButton);
        layout->addWidget(exitButton);

        connect(startPauseButton, &QPushButton::clicked,this, &Chrono::startPauseChrono);
        connect(resetButton, &QPushButton::clicked, this, &Chrono::resetChrono);
        connect(exitButton, &QPushButton::clicked, this, &Chrono::exitChrono);

        chronoWindow->show();
        chronoWindow->setAttribute(Qt::WA_DeleteOnClose);

        start_time = QDateTime::currentDateTime();
        chrono.start(10);
    }
}

void Chrono::startPauseChrono() {
    if(!isRunning){
        start_time = QDateTime::currentDateTime();
        chrono.start(10);
        isRunning = true;
        isPaused = false;
        startPauseButton->setText("Pause");
    } else {
        if(!isPaused){
            elapsed += start_time.msecsTo(QDateTime::currentDateTime());
            chrono.stop();
            isRunning = false;
            isPaused = true;
            startPauseButton->setText("Resume");
    } else {
        start_time = QDateTime::currentDateTime();
        chrono.start(10);
        isRunning = true;
        isPaused = false;
        startPauseButton->setText("Pause");
        }
    }
}

void Chrono::resetChrono() {
    elapsed = 0;
    displayTime = "00:00,00";
    chronoDisplay->setText(displayTime);
    startPauseButton->setText("Start");
    isRunning = false;
    isPaused = false;
    chrono.stop();
}


void Chrono::update() {
    if (isRunning) {
        qint64 currentElapsed = elapsed + start_time.msecsTo(QDateTime::currentDateTime());
        qDebug() << "Elapsed time: " << elapsed;
        int milliseconds = currentElapsed % 1000;
        int seconds = (currentElapsed % (60 * 1000)) / 1000;
        int minutes = (currentElapsed % (60 * 60 * 1000)) / (60 * 1000);
        displayTime = QString("%1:%2,%3")
                .arg(minutes, 2, 10, QChar('0'))
                .arg(seconds, 2, 10, QChar('0'))
                .arg(milliseconds, 3, 10, QChar('0'));
        chronoDisplay->setText(displayTime);
    }
}
    void Chrono::exitChrono() {
        chronoWindow->close();
    }