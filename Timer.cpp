//
// Created by andrea on 13/12/23.
//

#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include "Timer.h"

Timer::Timer(QObject *parent) : QObject(parent), remainingHours(0), remainingMinutes(0), remainingSeconds(0), timerSetupDialog(
        nullptr), timerWindow(nullptr), displayLabel(nullptr){
    connect(&timer, &QTimer::timeout, this, &Timer::updateTimer);
}
void Timer::setInitialTime(int hours, int minutes, int seconds) {
    remainingHours = hours;
    remainingMinutes = minutes;
    remainingSeconds = seconds;
    emit timeUpdated(remainingHours,remainingMinutes,remainingSeconds);
}
void Timer::start() {
    if(!timerSetupDialog){
        createTimerDialog();
    }
    if(timerWindow) {
        timerWindow->show();
        timer.start(1000);
    }
}

void Timer::updateTimer() {
    if(remainingHours == 0 && remainingMinutes == 0 && remainingSeconds == 0){
        timer.stop();
        emit timeout();
        if(timerWindow){
            QTimer::singleShot(1000,timerWindow, &QWidget::close);
        }
    } else {
        if (remainingSeconds > 0){
            remainingSeconds--;
        } else {
            if(remainingMinutes > 0){
                remainingMinutes--;
                remainingSeconds = 59;
            } else {
                if(remainingHours > 0){
                    remainingHours--;
                    remainingMinutes = 59;
                    remainingSeconds = 59;
                }
            }
        }
        emit timeUpdated(remainingHours,remainingMinutes,remainingSeconds);
        updateTimerWindow();
    }
}
void Timer::createTimerDialog(){
    timerSetupDialog = new QDialog;
    timerSetupDialog->setWindowTitle("Set Countdown Timer");
    timerSetupDialog->resize(300,300);
    QVBoxLayout* timerSetupLayout = new QVBoxLayout(timerSetupDialog);

    QLabel* label = new QLabel("Set Initial Time (HH:MM:SS)", timerSetupDialog);
    QLineEdit* timeInput = new QLineEdit(timerSetupDialog);

    QPushButton* startButton = new QPushButton("Start", timerSetupDialog);
    QPushButton* cancelButton = new QPushButton("Cancel", timerSetupDialog);

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

        QVBoxLayout* timerWindowLayout = new QVBoxLayout(timerWindow);
        QLabel* timerLabel = new QLabel("Time Remaining:", timerWindow);
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
    if(timerWindow){
        QString timeString = QString("%1:%2:%3")
                .arg(remainingHours, 2, 10, QChar('0'))
                .arg(remainingMinutes, 2, 10, QChar('0'))
                .arg(remainingSeconds, 2, 10, QChar('0'));
        QLabel* label = timerWindow->findChild<QLabel*>("displayLabel");
        if(label){
            label->setText(timeString);
        }
    }
}