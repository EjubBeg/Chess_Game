#include "knigth.h"

Knigth::Knigth(QString s,QGraphicsItem *p)
    :figure(s,p)
{
    setpic();

}
void Knigth::setpic()
{
    if(figurecolor == "WHITE")
        setPixmap(QPixmap(":/pics/pics/WKnigth.png"));
    else
        setPixmap(QPixmap(":/pics/pics/BKnigth.png"));
}
bool Knigth::can_move(int x,int y)
{
if((abs(x-getx())>2)||(abs(y-gety())>2))
    return false;

if((abs(x-getx())+abs(y-gety()))==3)
    return true;

return false;
}
QString Knigth::kind()
{
    return "Knight";
}
