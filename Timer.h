//
// Created by andrea on 13/12/23.
//

#ifndef ELABORATO_PROG_TIMER_H
#define ELABORATO_PROG_TIMER_H

#include <QDialog>
#include "QObject"
#include "QTimer"


class Timer : public QObject {
    Q_OBJECT
public:
    explicit Timer(QObject *parent = nullptr);

    void setInitialTime(int hours, int minutes, int seconds);
    void start();
    signals:
    void timeUpdated(int hours, int minutes, int seconds);
    void timeout();
private slots:
    void updateTimer();
    void updateTimerWindow();
    void createTimerDialog();
    void createTimerWindow();
private:
    QTimer timer;
    QDialog* timerSetupDialog;
    QLabel* displayLabel;
    QWidget* timerWindow;
    int remainingHours;
    int remainingMinutes;
    int remainingSeconds;
};


#endif //ELABORATO_PROG_TIMER_H
