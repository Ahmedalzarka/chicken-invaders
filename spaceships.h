#ifndef SPACESHIPS_H
#define SPACESHIPS_H
#include <QGraphicsItem>
#include <QObject>

class SpaceShips: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    SpaceShips();
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void createChicken();
};

#endif
 // SPACESHIPS_H
