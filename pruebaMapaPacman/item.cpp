#include "item.h"

Item::Item(const int &x, const int &y, const int &width, const int &height):
    QGraphicsRectItem(x,y,width-1,height-1)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

}

bool Item::colisiona(Item *objeto)
{
    if (objeto->getX() + objeto->getWidth() <= x) {
        return false;
    }
    if (objeto->getY() + objeto->getHeight()  <= y) {
        return false;
    }
    if (objeto->getX() >= x + width) {
        return false;
    }
    if (objeto->getY() >= y + height) {
        return false;
    }
    return true;
}

void Item::newPos(int x, int y)
{
    this->x = x;
    this->y = y;
    setPos(x, y);
}

int Item::getX() const
{
    return x;
}

int Item::getY() const
{
    return y;
}

int Item::getWidth() const
{
    return width;
}

int Item::getHeight() const
{
    return height;
}
