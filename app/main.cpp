#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication odeApp(argc, argv);
    MainWindow odeWindow;
    odeWindow.show();
    return odeApp.exec();
}
