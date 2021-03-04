#include "game.h"
#include <QPixmap>
#include <QDebug>
#include <QGraphicsTextItem>
#include "button.h"
#include <QLineEdit>
#include <QGraphicsProxyWidget>

Game::Game(QWidget *parent)
    :QGraphicsView(parent)
{
    //Making the Scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1600,900);
    setFixedSize(1600,900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(scene);
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::lightGray);
    setBackgroundBrush(brush);

    player1name= "Player1";
    player2name= "Player2";
    turn= "WHITE";

   chosen_figure=nullptr;

}

void Game::place_dead(figure* f)
{
dead.append(f);
QString b= "BLACK";
QString w= "WHITE";

int SHIFT = 35;
int yw = 0;
int yb=0;
int kw = 0;
int kb=0;
for(int i = 0; i<dead.size(); i++) {
if(dead[i]->getcolor()==b){
    if(yb == 6){
        kb++;
        yb = 0;
    }
dead[i]->setPos(40+SHIFT*yb,500+SHIFT*2*kb);
yb++;
continue;
}

if(dead[i]->getcolor()==w){
    if(yw == 6){
        kw++;
        yw = 0;
    }
    dead[i]->setPos(40+SHIFT*yw,100+SHIFT*2*kw);
    yw++;
    continue;
}
}
}




void Game::startapp()
{

    //Create the title
    QGraphicsTextItem *titleText = new QGraphicsTextItem("Best Chess game");
    QFont titleFont("arial" , 100);
    titleText->setFont( titleFont);
    titleText->setPos(width()/2 - titleText->boundingRect().width()/2,150);
    scene->addItem(titleText);
    currentitems.append(titleText);
    //
    QGraphicsTextItem *p1text = new QGraphicsTextItem("Player with White figures name");
    p1text->setPos(width()/2 - p1text->boundingRect().width()/2,600);
    scene->addItem(p1text);
    currentitems.append(p1text);

    //
    QGraphicsTextItem *p2text = new QGraphicsTextItem("Player with Black figures name");
    p2text->setPos(width()/2 - p2text->boundingRect().width()/2,700);
    scene->addItem(p2text);
    currentitems.append(p2text);

    //Start Button
    Button * playButton = new Button("Start");
    playButton->setPos(width()/2 - playButton->boundingRect().width()/2,400);
    connect(playButton,SIGNAL(clicked()) , this , SLOT(start()));
    scene->addItem(playButton);
    currentitems.append(playButton);

    //Quit Button
    Button * quitButton = new Button("Quit");
    quitButton->setPos(width()/2 - quitButton->boundingRect().width()/2,475);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
    //drawChessBoard();
    currentitems.append(quitButton);

    Button* Apply1 = new Button("Save names");
    Apply1->setPos( width()/2 - Apply1->boundingRect().width()/2,800);
    connect(Apply1,SIGNAL(clicked()),this,SLOT(savename()));
    scene-> addItem(Apply1);
    currentitems.append(Apply1);

    pLineEdit = new QLineEdit(player1name);
    pProxyWidget =scene->addWidget(pLineEdit);
    pProxyWidget->setPos(width()/2 - pProxyWidget->boundingRect().width()/2,650);
    scene->addItem(pProxyWidget);
    currentitems.append(pProxyWidget);

    pLineEdit2 = new QLineEdit(player2name);
    pProxyWidget2 =scene->addWidget(pLineEdit2);
    pProxyWidget2->setPos(width()/2 - pProxyWidget2->boundingRect().width()/2,750);
    scene->addItem(pProxyWidget2);
    currentitems.append(pProxyWidget2);
}
Game::~Game()
{
}
void Game::savename()
{
    player1name=pLineEdit->text();
    player2name=pLineEdit2->text();
}
void Game::start()
{
deleter();

turndisplayer = new QGraphicsTextItem();
turndisplayer->setPos(1300,50);
turndisplayer->setZValue(1);
turndisplayer->setDefaultTextColor(Qt::black);
turndisplayer->setFont(QFont("",10));
turndisplayer->setPlainText(turn);
scene->addItem(turndisplayer);
currentitems.append(turndisplayer);


Movedispalyer = new QGraphicsTextItem("Chose : ");
Movedispalyer->setPos(1300,(height()/2));
Movedispalyer->setZValue(1);
Movedispalyer->setDefaultTextColor(Qt::black);
Movedispalyer->setFont(QFont("",10));
scene->addItem(Movedispalyer);
currentitems.append(Movedispalyer);

move = new QGraphicsTextItem("Something");
move->setPos(1300,(height()/2)+25);
move->setZValue(1);
move->setDefaultTextColor(Qt::black);
move->setFont(QFont("",10));
scene->addItem(move);
currentitems.append(move);

QGraphicsTextItem* whitePiece = new QGraphicsTextItem();
whitePiece->setPos(50,50);
whitePiece->setZValue(1);
whitePiece->setDefaultTextColor(Qt::black);
whitePiece->setFont(QFont("",10));
whitePiece->setPlainText(player1name + "'s deadfigures");
scene->addItem(whitePiece);
currentitems.append(whitePiece);


QGraphicsTextItem *blackPiece = new QGraphicsTextItem();
blackPiece->setPos(50,(height()/2));
blackPiece->setZValue(1);
blackPiece->setDefaultTextColor(Qt::black);
blackPiece->setFont(QFont("",10));
blackPiece->setPlainText(player2name + "'s deadfigures");
scene->addItem(blackPiece);
currentitems.append(blackPiece);

myboard = new chessboard();
myboard->make_board_scene();
myboard->set_board();
myboard->add_figures_to_game();
}
void Game::deleter()
{
    for(int i =0 ; i < currentitems.size(); i++)
       scene->removeItem(currentitems[i]);
}
void Game::add_to_cur_items(QGraphicsItem* a)
{
    currentitems.append(a);
}
void Game::delete_single(figure* f)
{
  scene->removeItem(f);
}

void Game::exit()
{
 deleter();


 QGraphicsTextItem *titleText = new QGraphicsTextItem(winner + " won this match");
 QFont titleFont("arial" , 50);
 titleText->setFont( titleFont);
 titleText->setPos(width()/2 - titleText->boundingRect().width()/2,150);
 scene->addItem(titleText);
 currentitems.append(titleText);

 Button * quitButton = new Button("Quit");
 quitButton->setPos(width()/2 - quitButton->boundingRect().width()/2,600);
 connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
 scene->addItem(quitButton);
 //drawChessBoard();
 currentitems.append(quitButton);

 Button* Apply1 = new Button("New Game");
 Apply1->setPos( width()/2 - Apply1->boundingRect().width()/2,400);
 connect(Apply1,SIGNAL(clicked()),this,SLOT(start()));
 scene-> addItem(Apply1);
 currentitems.append(Apply1);





}

