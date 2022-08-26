#include "tools.h"

QList<QGraphicsRectItem*> leerMuros()
{
    std::ifstream file;
    QList<std::string> m;
    QList<QGraphicsRectItem*> muros;

    file.open("mapaGoogle.txt");
    std::string c;
    while(!file.eof()){
        getline(file, c);
        m.append(c);
    }
    m.removeLast();

    file.close();

    QPen pen(QColor(255,0,0));
    pen.setWidth(1);

    for(int i=0; i < m.size(); ++i){
        for(int j=0; j < int(m[i].length()); ++j){
            if(m[i][j] == 'X'){
                muros.append(new QGraphicsRectItem(j*wh, i*wh, wh-1, wh-1));
            }
        }
    }
    for(int i=0; i<muros.size(); ++i){
        muros[i]->setPen(pen);
    }

    return muros;
}

QList<Item *> muracos()
{
    std::ifstream file;
    QList<std::string> m;
    QList<Item*> muros;

    file.open("mapaGoogle.txt");
    std::string c;
    while(!file.eof()){
        getline(file, c);
        m.append(c);
    }
    m.removeLast();

    file.close();

    //QPen pen(QColor(255,0,0));
    //pen.setWidth(1);

    for(int i=0; i < m.size(); ++i){
        for(int j=0; j < int(m[i].length()); ++j){
            if(m[i][j] == 'X'){
                muros.append(new Item(j*wh, i*wh, wh, wh));
            }
        }
    }
//    for(int i=0; i<muros.size(); ++i){
//        muros[i]->setPen(pen);
//    }

    return muros;
}
