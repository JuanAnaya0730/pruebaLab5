#include "mainwindow.h"
#include "level.h"
#include "pruebaitem.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //level game;
    //game.show();

    pruebaItem i;
    i.show();

    return a.exec();
}
