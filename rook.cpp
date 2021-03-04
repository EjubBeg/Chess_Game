#include "rook.h"

Rook::Rook(QString s, QGraphicsItem* p)
        :figure(s,p)
{
    setpic();

}
void Rook::setpic()
{
    if(figurecolor == "WHITE")
        setPixmap(QPixmap(":/pics/pics/WRook.png"));
    else
        setPixmap(QPixmap(":/pics/pics/BRook.png"));
}

bool Rook::can_move(int x,int y)
{
return (currentBox->ishorizontal_vertical(x,y))&&(safe_hor_ver_root(x,y));
}
QString Rook::kind()
{
    return "Rook";
}
