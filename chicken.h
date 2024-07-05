#ifndef CHICKEN_H
#define CHICKEN_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QAbstractItemModel>

class Chicken : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Chicken();

public slots:
    void move();

private:
};

#endif // CHICKEN_H
