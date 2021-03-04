#include "king.h"

King::King(QString s,QGraphicsItem *p)
    :figure(s,p)
{
    setpic();

}

void King::setpic()
{
    if(figurecolor == "WHITE")
        setPixmap(QPixmap(":/pics/pics/WKing.png"));
    else
        setPixmap(QPixmap(":/pics/pics/BKing.png"));
}
bool King::can_move(int x,int y)
{
    if(firstMove==true)
    {
    if(getx()==0)
    {
        if((y==1)||(y==2))
        {
        if(isfirst_move(0,0)&&safe_hor_ver_root(0,0))
        {
            currentBox->castling(1);
            kill_chosen();
            return false;
        }
        }
        if(y==6)
        {
         if(isfirst_move(0,7)&&safe_hor_ver_root(0,7))
         {
             currentBox->castling(2);
             kill_chosen();

             return false;
         }
        }
  }

    if(getx()==7)
    {
        if((y==1)||(y==2))
        {
        if(isfirst_move(7,0)&&safe_hor_ver_root(7,0))
        {
            currentBox->castling(3);
            kill_chosen();

            return false;
        }
        }
        if(y==6)
        {
         if(isfirst_move(7,7)&&safe_hor_ver_root(7,7))
         {
             currentBox->castling(4);
             kill_chosen();
             return false;
         }
        }
    }
    }

if((abs(x-getx())>1)||(abs(y-gety())>1))
    return false;

return true;
}
QString King::kind()
{
    return "King";
}
