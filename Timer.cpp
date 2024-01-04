//
// Created by andrea on 13/12/23.
//

#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>
#include "Timer.h"  //Classe che implementa il timer

Timer::Timer(QObject *parent) : QObject(parent), timerSetupDialog(
        nullptr), timerWindow(nullptr), displayLabel(nullptr), remainingTime(new Time(this,0,0,0)) {
    connect(&timer, &QTimer::timeout, this, &Timer::updateTimer);
}
Timer::~Timer() {
    delete timerWindow;
}

void Timer::setInitialTime(int hours, int minutes, int seconds) {
    remainingTime->set(hours,minutes,seconds);
    emit timeUpdated(hours,minutes,seconds);
}
void Timer::start() {
    if(!timerSetupDialog && remainingTime->getHours() == 0 && remainingTime->getMinutes() == 0 && remainingTime->getSeconds() == 0){
            createTimerDialog();
        }
        if(!timerWindow) {
            createTimerWindow();
            timer.start(1000);
        } else {
            timerWindow->show();
            timer.start(1000);
    }
}

void Timer::updateTimer() {
    if(remainingTime->getHours() == 0 && remainingTime->getMinutes() == 0 && remainingTime->getSeconds() == 0){
        timer.stop();
        emit timeout();
        if(timerWindow){
            QTimer::singleShot(1000,timerWindow, &QWidget::close);
        }
    } else {
        remainingTime->decreaseSecond();
        emit timeUpdated(remainingTime->getHours(),remainingTime->getMinutes(),remainingTime->getSeconds());
        updateTimerWindow();
    }
}
void Timer::createTimerDialog(){
    timerSetupDialog = new QDialog;
    timerSetupDialog->setWindowTitle("Set Countdown Timer");
    timerSetupDialog->resize(300,300);
    auto* timerSetupLayout = new QVBoxLayout(timerSetupDialog);

    auto* label = new QLabel("Set Initial Time (HH:MM:SS)", timerSetupDialog);
    auto* timeInput = new QLineEdit(timerSetupDialog);

    auto* startButton = new QPushButton("Start", timerSetupDialog);
    auto* cancelButton = new QPushButton("Cancel", timerSetupDialog);

    timerSetupLayout->addWidget(label);
    timerSetupLayout->addWidget(timeInput);
    timerSetupLayout->addWidget(startButton);
    timerSetupLayout->addWidget(cancelButton);

    QObject::connect(startButton, &QPushButton::clicked, [this, &timeInput](){
        QStringList timeParts = timeInput->text().split(':');
        if(timeParts.size() == 3){
            int hours = timeParts[0].toInt();
            int minutes = timeParts[1].toInt();
            int seconds = timeParts[2].toInt();
            setInitialTime(hours,minutes,seconds);
            createTimerWindow();
            timerWindow->show();
            QObject::connect(this, &Timer::timeout, [this](){
                timerSetupDialog->accept();
            });
            timer.start();
            timerSetupDialog->accept();
        } else {
            QMessageBox::critical(timerSetupDialog, "Error!", "Invalid time format! Please use HH:MM:SS");
        }
    });
    QObject::connect(cancelButton, &QPushButton::clicked, [this](){
        timerSetupDialog->reject();
    });
    timerSetupDialog->exec();
}
void Timer::createTimerWindow() {
    if (!timerWindow) {
        timerWindow = new QWidget;
        timerWindow->setWindowTitle("Timer App");
        timerWindow->resize(300,300);

        auto* timerWindowLayout = new QVBoxLayout(timerWindow);
        auto* timerLabel = new QLabel("Time Remaining:", timerWindow);
        displayLabel = new QLabel("", timerWindow);

        timerWindowLayout->addWidget(timerLabel);
        timerWindowLayout->addWidget(displayLabel);

        timerWindow->show();

        QObject::connect(this, &Timer::timeUpdated, [this](int h, int m, int s) {
            if(displayLabel) {
                QString timeString = QString("%1:%2:%3")
                        .arg(h, 2, 10, QChar('0'))
                        .arg(m, 2, 10, QChar('0'))
                        .arg(s, 2, 10, QChar('0'));
                displayLabel->setText(timeString);
            }
        });
        QObject::connect(this, &Timer::timeout, [this](){
            if(displayLabel){
                displayLabel->setText("TIMEOUT!");
            }
            if(timerWindow){
                QTimer::singleShot(1000,timerWindow, &QWidget::close);
            }
        });
    }
}
void Timer::updateTimerWindow() {
    if(timerWindow ) {
        if (displayLabel) {
            QString timeString = QString("%1:%2:%3")
                    .arg(remainingTime->getHours(), 2, 10, QChar('0'))
                    .arg(remainingTime->getMinutes(), 2, 10, QChar('0'))
                    .arg(remainingTime->getSeconds(), 2, 10, QChar('0'));
            displayLabel->setText(timeString);
        }
    }
}

Time *Timer::getRemainingTime() const {
    return remainingTime;
}

QString Timer::getDisplayLabelText() {
    if(displayLabel) {
        QString labelText = displayLabel->text();
        return labelText;
    } else {
        return QString();
    }
}



