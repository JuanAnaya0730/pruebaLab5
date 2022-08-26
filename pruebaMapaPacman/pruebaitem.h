#ifndef PRUEBAITEM_H
#define PRUEBAITEM_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QDebug>
#include "item.h"
#include "tools.h"

class pruebaItem : public QGraphicsView
{
private:
    QGraphicsScene *scene;
    Item *pacman;
    Item *muro;

    QList<Item*> mapa;

public:
    pruebaItem();

    void keyPressEvent(QKeyEvent *event);
    bool colisiona();
};

#endif // PRUEBAITEM_H
