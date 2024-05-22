#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //Set random position
    int random_number = rand()% 700;
    setPos(random_number, 0);

    //drew rect
    setPixmap(QPixmap(":/images/science.png"));

    //connect
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);

}

void Enemy::move()
{
    //move enemy down
    setPos(x(), y() +5);
    if(pos().y() > 600)
    {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }

}
