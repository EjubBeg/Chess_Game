#include "bishop.h"

Bishop::Bishop(QString s,QGraphicsItem *parent)
    :figure(s,parent)
{
setpic();
}

void Bishop::setpic()
{
    if(figurecolor == "WHITE")
        setPixmap(QPixmap(":/pics/pics/WBishop.png"));
    else
        setPixmap(QPixmap(":/pics/pics/BBishop.png"));
}
bool Bishop::can_move(int x,int y)
{

    return ((currentBox->isdiagonal(x,y))&&safe_dia_root(x,y));
}

QString Bishop::kind()
{
    return "Bishop";
}
