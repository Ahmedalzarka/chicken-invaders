#include "spaceships.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QKeyEvent>
#include "chicken.h"

SpaceShips::SpaceShips() {

    setPixmap(QPixmap(":/ship.png"));
}
void SpaceShips::keyPressEvent(QKeyEvent *event)
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

}
void SpaceShips::createChicken()
{ Chicken *chicken = new Chicken();
  scene()->addItem(chicken);

}
