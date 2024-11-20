#include "personaje.h"

personaje::personaje()
{

}

personaje::personaje(int x, int y, int w, int h)
{
    this->x=x;
    this->y=y;
    this->w=w;
    this->h=h;
    setPos(x,y);
    velocidad=5;
}

QRectF personaje::boundingRect() const
{
    return QRectF(x,y,w,h);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::red);
    //painter->drawRect(boundingRect());

    QPixmap pxmap(":/pacman/pacman.png");
    painter->drawPixmap(boundingRect(), pxmap,pxmap.rect());

}

void personaje::MoverArriba()
{
    y=y-velocidad;
    setPos(x,y);
}

void personaje::MoverAbajo()
{
    y=y+velocidad;
    setPos(x,y);
}

void personaje::MoverIzq()
{
    x=x-velocidad;
    setPos(x,y);
}

void personaje::MoverDer()
{
    x=x+velocidad;
    setPos(x,y);
}
