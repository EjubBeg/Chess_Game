#include "queen.h"

Queen::Queen(QString s,QGraphicsItem* p)
    :figure(s,p)
{
    setpic();

}
void Queen::setpic()
{
    if(figurecolor == "WHITE")
        setPixmap(QPixmap(":/pics/pics/WQueen.png"));
    else
        setPixmap(QPixmap(":/pics/pics/BQueen.png"));
}

bool Queen::can_move(int x,int y)
{

return (((currentBox->ishorizontal_vertical(x,y))&&(safe_hor_ver_root(x,y)))||((currentBox->isdiagonal(x,y))&&(safe_dia_root(x,y))));
}
QString Queen::kind()
{
    return "Queen";
}
