//
// Created by andrea on 12/12/23.
//

#ifndef ELABORATO_PROG_CLOCK_H
#define ELABORATO_PROG_CLOCK_H

#include <QObject>
#include <QTimer>
#include <QDateTime>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "Time.h"
#include "Date.h"

class Clock : public QObject{ //Classe che rappresenta un orologio con data e orario corrente
    Q_OBJECT
public:
    explicit Clock(QObject *parent = nullptr);
    void start();
    void update();
    QLabel *clockDisplay;
private slots:
    void exitClock();
private:
    QWidget *clockWindow;
    QVBoxLayout *layout;
    QTimer timer;

    QPushButton* exitButton;
    Date *currentDate;
    Time *currentTime;
};

#endif //ELABORATO_PROG_CLOCK_H
