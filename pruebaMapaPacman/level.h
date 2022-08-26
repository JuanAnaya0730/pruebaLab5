#ifndef LEVEL_H
#define LEVEL_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPen>
#include "tools.h"

class level : public QGraphicsView
{
private:
    QGraphicsScene *scene;
    QList<QGraphicsRectItem*> muros;
    QGraphicsRectItem *pacman;

public:
    level();

    //void keyPressEvent(QKeyEvent *event);
    bool colisiona();

};

#endif // LEVEL_H
