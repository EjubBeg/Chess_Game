#ifndef FIGURE_H
#define FIGURE_H
#include "singlesquare.h"
#include "QGraphicsPixmapItem"

class singlesquare;

class figure:public QGraphicsPixmapItem
{
public:

    figure(QString ,QGraphicsItem *parent = 0);


    void setsquare(singlesquare*);
    singlesquare *getsquare() ;
    QString getcolor() ;
    //Returns type of figures
    virtual QString kind()=0;
    //sets the picture to the coresponding figure
    virtual void setpic() = 0;
    //Cheks is the move legal
    virtual bool can_move(int x,int y)=0;
    //Returns the color of the figure on wanted square
    QString search(int ,int );
    //Cheks is the line blocked with other figure
    bool safe_hor_ver_root(int x,int y);
    //Cheks is the diagonal line blocked with other figure
    bool safe_dia_root(int x,int y);
    bool isfirst_move(int x,int y);
    //Changes the chosen figure(figure to move)
    void kill_chosen();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QString searchkind(int ,int );
    bool isPlaced;
    bool firstMove;
    int getx();
    int gety();
    QString figurecolor;
    singlesquare *currentBox;


};

#endif // FIGURE_H
