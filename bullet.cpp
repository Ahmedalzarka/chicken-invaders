#include "chicken.h"
#include "bullet.h"
#include "stats.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

Bullet::Bullet(): QObject(), QGraphicsPixmapItem()
{
    this->setPixmap(QPixmap(":/new/ss/imgs/red_laser.png").scaled(35,35));


    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet :: move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    int n = colliding_items.size();
    for (int i = 0; i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Chicken)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            Stats::increase();
            return;
        }
    }



    setPos(x(),y()-10);
    if (pos().y() + pixmap().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
