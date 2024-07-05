#ifndef SHIP_H
#define SHIP_H
#include <QGraphicsItem>
#include <QObject>

class Ship: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Ship();
public:
    void keyPressEvent(QKeyEvent * event);

};

#endif // SHIP_H
