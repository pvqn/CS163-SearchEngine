#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     mainpage w;
    w.setWindowTitle("");
    w.setAttribute(Qt::WA_MacShowFocusRect, 1);
    w.show();
    return a.exec();
}
