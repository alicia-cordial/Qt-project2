#include <QApplication>
#include <QgraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "Game.h"
#include "Enemy.h"
#include "Score.h"
#include "Health.h"

Game::Game(QWidget *parent)
{
// create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    //create an item to put into the scene
    player = new Player();
    player->setPos(400, 500);

    // maje rect focusabke
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add the item to the scene
    scene->addItem(player);

    //create the score/health
    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);



    //spawn enemies
    QTimer * timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    show();
}
