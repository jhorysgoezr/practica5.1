#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QList>
#include "muro.h"

class personaje :public QGraphicsItem
{
    //atributos
    int x;
    int y;
    int w;
    int h;
    int velocidad;

    // Método privado para verificar colisiones
    bool verificarColision(int newX, int newY);

public:
    personaje();
    personaje(int x, int y, int w, int h);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void MoverArriba();
    void MoverAbajo();
    void MoverIzq();
    void MoverDer();
};

#endif // PERSONAJE_H
