#include "level.h"
#include <QDebug>

level::level()
{
    //setRenderHints( QPainter::Antialiasing );

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 472, 144);
    setScene(scene);

    muros = leerMuros();
    for(int i=0; i<muros.size(); ++i){
        scene->addItem(muros[i]);
    }

    scene->addPixmap(QPixmap(":/google_pacmanMap.png"));

    //pacman = new QGraphicsPixmapItem(QPixmap(":/3.png"));
    pacman = new QGraphicsRectItem(0,0,(wh*2)-1,(wh*2)-1);
    //QBrush b(QPixmap(":/3.png"));
    //pacman->setBrush(b);
    pacman->setPen(QPen(QColor(255,0,0)));
    pacman->setPos(wh*25, wh*15);
    qDebug() << pacman->rect() << " " << muros[0]->rect();

    scene->addItem(pacman);

}

//void level::keyPressEvent(QKeyEvent *event)
//{
//    if(event->key() == Qt::Key_Up){
//        pacman->setPos(pacman->x(), pacman->y()-1);
//        if(colisiona()){ pacman->setPos(pacman->x(), pacman->y()+1); }
//    }
//    else if(event->key() == Qt::Key_Down){
//        pacman->setPos(pacman->x(), pacman->y()+1);
//        if(colisiona()){ pacman->setPos(pacman->x(), pacman->y()-1); }
//    }
//    else if(event->key() == Qt::Key_Left){
//        pacman->setPos(pacman->x()-1, pacman->y());
//        if(colisiona()){ pacman->setPos(pacman->x()+1, pacman->y()); }
//    }
//    else if(event->key() == Qt::Key_Right){
//        pacman->setPos(pacman->x()+1, pacman->y());
//        if(colisiona()){ pacman->setPos(pacman->x()-1, pacman->y()); }
//    }else if(event->key() == Qt::Key_G){
//        scale(5, 5);
//    }
//}

bool level::colisiona()
{
    for(int i=0; i<muros.size(); ++i){
        if(pacman->collidesWithItem(muros[i])){ return true; }
    }
    return false;
}
