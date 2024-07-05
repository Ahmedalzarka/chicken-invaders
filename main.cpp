#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include "ship.h"
#include "stats.h"
#include "chicken.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsPixmapItem * player = new Ship();
    scene-> addItem(player);
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2,view->height() - player->pixmap().height());

    QGraphicsTextItem* scoreText = new QGraphicsTextItem();
    QGraphicsTextItem* healthText = new QGraphicsTextItem();

    scene->addItem(scoreText);
    scene->addItem(healthText);

    Stats::setHealthText(healthText);
    Stats::setScoreText(scoreText);

    QTimer* t = new QTimer();
    QObject::connect(t, &QTimer::timeout, [=]() {
        Chicken* chicken = new Chicken();
        scene->addItem(chicken);
    });
    t->start(2000);

    QPixmap back(":/new/ss/imgs/space.jpg");
    scene->setBackgroundBrush(QBrush(back));

    return a.exec();
}
