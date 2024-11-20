#ifndef MURO_H
#define MURO_H

#include <QGraphicsItem>
#include <QPainter>

class muro : public QGraphicsItem {
private:
    int x, y, w, h;

public:
    muro();
    muro(int x, int y, int w, int h);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // MURO_H
