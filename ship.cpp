#include "ship.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include "chicken.h"
#include "bullet.h"

Ship::Ship()
{
    setPixmap(QPixmap(":/new/ss/imgs/ship.png"));

}

void Ship::keyPressEvent(QKeyEvent *event)
{
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0)
            setPos(x()-10,y());

    }

    else if(event->key()== Qt::Key_Right)
    {
        if(x()+100<800)
            setPos(x()+10,y());
    }

    else if(event->key() == Qt::Key_Up){
        if(y() > 0)
            setPos(x(), y() - 10);
    }

    else if(event->key() == Qt::Key_Down){
        if(y() + 100 < 600)
            setPos(x(), y() + 10);
    }
    else if(event->key() == Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+20,y());
        scene()->addItem(bullet);
    }
}

