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

class Clock : public QObject{
    Q_OBJECT
public:
    explicit Clock(QObject *parent = nullptr);
    void start();
private slots:
    void update();
    void exitClock();
private:
    QWidget *clockWindow;
    QVBoxLayout *layout;
    QLabel *clockDisplay;
    QPushButton* exitButton;
    QTimer timer;
};

#endif //ELABORATO_PROG_CLOCK_H
