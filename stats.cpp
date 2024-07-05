#include "stats.h"
#include <QMessageBox>
#include <QString>
#include <QGraphicsScene>
#include <QFont>

int Stats::health = 3;
int Stats::score = 0;
QGraphicsTextItem* Stats::healthText = nullptr;
QGraphicsTextItem* Stats::scoreText = nullptr;

void Stats::setHealthText(QGraphicsTextItem* hlthText) {
    healthText = hlthText;
    healthText->setFont(QFont("arial", 22));
    healthText->setDefaultTextColor(Qt::white);
    healthText->setPlainText("Health: " + QString::number(health));
    healthText->setPos(20,20);
}

void Stats::setScoreText(QGraphicsTextItem* scrText){
    scoreText = scrText;
    scoreText->setFont(QFont("arial", 22));
    scoreText->setDefaultTextColor(Qt::cyan);
    scoreText->setPlainText("Score: " + QString::number(score));
    scoreText->setPos(20,60);
}

void Stats::increase(){
    score++;
    scoreText->setPlainText("Score: " + QString::number(score));
}

void Stats::decrease(){
    if(health > 0){
        health--;
    }
    healthText->setPlainText("Health: " + QString::number(health));
    scoreText->setPlainText("Score: " + QString::number(score));
}



