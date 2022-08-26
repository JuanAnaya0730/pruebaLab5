#include "pruebaitem.h"

pruebaItem::pruebaItem()
{
    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(wh*59, wh*18);
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, wh*59, wh*18);
    setScene(scene);

    pacman = new Item(0, 0, wh*2, wh*2);
    muro = new Item(200, 100, 50, 20);

    pacman->newPos(wh*25, wh*15);
    scene->setFocusItem(pacman);

    mapa = muracos();
    for(int i=0; i<mapa.size(); ++i){ scene->addItem(mapa[i]); }

    //scene->addPixmap(QPixmap(":/google_pacmanMap.png"));

    //pacman->setBrush(QBrush(QPixmap(":/3.png")));
    //pacman->setPen(QPen(QBrush(QPixmap(":/3.png")), 1));
    //QPen p(QColor(255,0,0));
    //p.setWidth(1);
    //pacman->setPen(p);

    scene->addItem(pacman);
    //scene->addItem(muro);
}

void pruebaItem::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up){
        pacman->newPos(pacman->getX(), pacman->getY()-1);
        if(colisiona()){ pacman->newPos(pacman->getX(), pacman->getY()+1); }
    }
    else if(event->key() == Qt::Key_Down){
        pacman->newPos(pacman->getX(), pacman->getY()+1);
        if(colisiona()){ pacman->newPos(pacman->getX(), pacman->getY()-1); }
    }
    else if(event->key() == Qt::Key_Left){
        pacman->newPos(pacman->getX()-1, pacman->getY());
        if(colisiona()){ pacman->newPos(pacman->getX()+1, pacman->getY()); }
    }
    else if(event->key() == Qt::Key_Right){
        pacman->newPos(pacman->getX()+1, pacman->getY());
        if(colisiona()){ pacman->newPos(pacman->getX()-1, pacman->getY()); }
    }else if(event->key() == Qt::Key_G){
        scale(2, 2);
    }
}

bool pruebaItem::colisiona()
{
    for(int i=0; i<mapa.size(); ++i){
        if(pacman->colisiona(mapa[i])){ return true; }
    }
    return false;
}
