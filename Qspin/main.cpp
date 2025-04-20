#include "mainwindow.h"
#include<QFile>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;

    QFile styleFile("Widget.css");
    styleFile.open(QIODevice::ReadOnly);
    QString style=QString::fromLatin1(styleFile.readAll());
    a.setStyleSheet(style);

    w.show();
    return a.exec();
}
