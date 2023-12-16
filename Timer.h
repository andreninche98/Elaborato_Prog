//
// Created by andrea on 13/12/23.
//

#ifndef ELABORATO_PROG_TIMER_H
#define ELABORATO_PROG_TIMER_H

#include <QDialog>
#include "QLabel"
#include "QObject"
#include "QTimer"


class Timer : public QObject { //Classe che rappresenta un timer con impostazione del conto alla rovescia
    Q_OBJECT                   // e messaggio di timeout alla fine di esso
public:
    explicit Timer(QObject *parent = nullptr);

    void setInitialTime(int hours, int minutes, int seconds);
    void start();
    void updateTimer();
    virtual void createTimerDialog();
    int remainingHours;
    int remainingMinutes;
    int remainingSeconds;
    QLabel* displayLabel;
    QWidget* timerWindow;
    signals:
    void timeUpdated(int hours, int minutes, int seconds);
    void timeout();
private slots:
    void createTimerWindow();
    void updateTimerWindow();


private:
    QTimer timer;
    QDialog* timerSetupDialog;

};


#endif //ELABORATO_PROG_TIMER_H
