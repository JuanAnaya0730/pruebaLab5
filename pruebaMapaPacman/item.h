#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsRectItem>

class Item : public QGraphicsRectItem
{
private:
    int x;
    int y;
    int width;
    int height;

public:
    Item(const int &x, const int &y, const int &width, const int &height);

    bool colisiona(Item *objeto);
    void newPos(int x, int y);
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
};

#endif // ITEM_H
