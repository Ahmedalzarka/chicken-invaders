#include "chicken.h"
#include <QTimer>
#include <QGraphicsScene>
#include "stats.h"
#include <QList>
#include <stdlib.h>


Chicken::Chicken(): QObject(), QGraphicsPixmapItem(){
    this->setPixmap(QPixmap(":/new/ss/imgs/chick.png").scaled(80,80));
    int randomNumber = rand() % 801 - 100;
    setPos(randomNumber, 0);

    //set timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Chicken::move()
{
    setPos(x(), y() + 10);
    //check if out of bounds of scene
    if (y() + pixmap().height() > scene()->height()){
        Stats::decrease();
        scene()->removeItem(this);
        delete this;
        return;
    }
}

