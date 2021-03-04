#ifndef GAME_H
#define GAME_H

#include "figure.h"
#include "button.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLineEdit>
#include "chessboard.h"
class chessboard;
class Game : public QGraphicsView
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    //Start the whole thing
    void startapp();
    //deletes the scene
    void deleter();
    //Makes the chessboard
    void makechessboard();
    //Places killed figure on the left "screens"
    void place_dead(figure*);
    QList <figure *> dead;
    figure* chosen_figure;
    chessboard* myboard;
    QGraphicsScene *scene;
    void add_to_cur_items(QGraphicsItem*);
    QString turn;
    QBrush brush;
    QGraphicsTextItem * turndisplayer;
    QGraphicsTextItem * Movedispalyer;
    QGraphicsTextItem * move;
    QGraphicsTextItem *check;
    QList <QGraphicsItem *> currentitems;
    QString player1name;
    QString player2name;
    QLineEdit* pLineEdit;
    QLineEdit* pLineEdit2;
    QGraphicsProxyWidget* pProxyWidget2;
    QGraphicsProxyWidget* pProxyWidget;
    QString winner;
    void delete_single(figure*);
void exit();
public slots:
    void start();
    void savename();
private:

    ~Game();
};
#endif // GAME_H
