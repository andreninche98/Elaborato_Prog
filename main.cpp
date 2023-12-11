#include "Time.h"
#include "Timer.h"
#include "Date.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QWidget window;
    window.setWindowTitle("Timer App");

    auto *layout = new QVBoxLayout(&window);

    auto *timeDisplay = new QLabel("00:00:00", &window);
    auto *startPauseButton = new QPushButton("Start", &window);
    auto *exitButton = new QPushButton("Exit", &window);

    layout->addWidget(timeDisplay);
    layout->addWidget(startPauseButton);
    layout->addWidget(exitButton);

    Time myTime;
    myTime.set(0,0,0);

    Date myDate;
    myDate.set(1,1,2023);

    Timer myTimer;

    QTimer timer;

    QObject::connect(&timer,&QTimer::timeout,[&](){
        if (myTimer.elapsed_seconds() % 2 == 0){
            myTime.seconds++;
            if(myTime.seconds == 60){
                myTime.seconds = 0;
                myTime.minutes++;
                if(myTime.minutes == 60){
                    myTime.minutes = 0;
                    myTime.hours++;
                    if(myTime.hours == 24){
                        myTime.hours = 0;
                    }
                }
            }
            timeDisplay->setText(myTime.display());
        }
    });
    QObject::connect(startPauseButton, &QPushButton::clicked, [&](){
        if(timer.isActive()){
            timer.stop();
            startPauseButton->setText("Start");
        } else {
            timer.start(1000);
            myTimer.start();
            startPauseButton->setText("Pause");
        }
    });
    QObject::connect(exitButton, &QPushButton::clicked, [&](){
        a.quit();
    });
    window.show();

    return a.exec();
}
