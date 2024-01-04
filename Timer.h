//
// Created by andrea on 13/12/23.
//

#ifndef ELABORATO_PROG_TIMER_H
#define ELABORATO_PROG_TIMER_H

#include <QDialog>
#include "QLabel"
#include "QObject"
#include "QTimer"
#include "Time.h"


class Timer : public QObject { //Classe che rappresenta un timer con impostazione del conto alla rovescia
    Q_OBJECT                   // e messaggio di timeout alla fine di esso
public:
    explicit Timer(QObject *parent);
    virtual ~Timer() override;
    void setInitialTime(int hours, int minutes, int seconds);
    void start();
    virtual void createTimerDialog();
    Time *getRemainingTime() const;
    QString getDisplayLabelText();
    void updateTimer();
signals:
    void timeUpdated(int hours, int minutes, int seconds);
    void timeout();
protected:
    virtual void createTimerWindow();
    virtual void updateTimerWindow();
private:
    QTimer timer;
    QDialog* timerSetupDialog;
    QLabel* displayLabel;
    QWidget* timerWindow;
    Time *remainingTime;
};

#endif //ELABORATO_PROG_TIMER_H
