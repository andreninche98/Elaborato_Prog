#include "Chrono.h"
#include "Date.h"
#include "Clock.h"
#include "Timer.h"
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QDialog>
#include <QLineEdit>
#include <QDebug>

int main(int argc, char *argv[]) {  //classe main utilizzata per inizializzare finestre di dialogo in cui scegliere tra le te funzionalità
    QApplication a(argc, argv);     // e quindi far partire una di esse a seconda della scelta
    a.setStyleSheet(
            "QDialog { width: 200px; height: 200px; } QLabel { font-size: 18pt; qproperty-alignment: AlignCenter; }");

    QDialog chooseModeDialog;
    chooseModeDialog.setWindowTitle("Choose Mode");
    chooseModeDialog.resize(300, 300);

    QVBoxLayout dialogLayout(&chooseModeDialog);
    QRadioButton chronoButton("Chrono", &chooseModeDialog);
    QRadioButton timerButton("Timer", &chooseModeDialog);
    QRadioButton clockButton("Clock", &chooseModeDialog);
    QPushButton okButton("OK", &chooseModeDialog);

    dialogLayout.addWidget(&chronoButton);
    dialogLayout.addWidget(&timerButton);
    dialogLayout.addWidget(&clockButton);
    dialogLayout.addWidget(&okButton);

    Chrono chrono;
    Timer timer(nullptr);
    Clock clock(nullptr);

    QObject::connect(&okButton, &QPushButton::clicked, [&]() {
        if (chronoButton.isChecked()) {
            chrono.start();
        } else {
            if (clockButton.isChecked()) {
            clock.start();
        } else {
            if (timerButton.isChecked()){
                timer.start();
            }
            }
        }
        chooseModeDialog.accept();
    });
    chooseModeDialog.exec();
    return QApplication::exec();
}
