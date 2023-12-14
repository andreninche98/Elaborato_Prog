//
// Created by andrea on 05/12/23.
//

#ifndef ELABORATO_PROG_CHRONO_H
#define ELABORATO_PROG_CHRONO_H
#include <QDateTime>
#include <QObject>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "Time.h"

class Chrono : public QObject{
    Q_OBJECT
private:
    QWidget* chronoWindow;
    QVBoxLayout* layout;
    QPushButton* startPauseButton;
    QPushButton* resetButton;
    QPushButton* exitButton;
    QLabel* chronoDisplay;
    QTimer chrono;
    Time myTime;
    QString displayTime;
    QDateTime start_time;
    qint64 elapsed;
    bool isRunning;
    bool isPaused;
public:
    explicit Chrono(QObject* parent = nullptr);
    void start();
private slots:
    void startPauseChrono();
    void resetChrono();
    void update();
    void exitChrono();
};


#endif //ELABORATO_PROG_CHRONO_H
