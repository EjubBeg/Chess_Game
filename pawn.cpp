#include "pawn.h"

Pawn::Pawn(QString s ,QGraphicsItem* p)
    :figure(s,p)
{
    setpic();

}
void Pawn::setpic()
{
    if(figurecolor == "WHITE")
        setPixmap(QPixmap(":/pics/pics/WPawn.png"));
    else
        setPixmap(QPixmap(":/pics/pics/Bpawn.png"));
}

bool Pawn::can_move(int x,int y)
{

    QString b ="BLACK";
    QString w ="WHITE";

    if((getcolor()==w)&&(x>getx()))
        return false;

    if((getcolor()==b)&&(x<getx()))
        return false;



    if((((getx()-1==x)&&(gety()+1==y))||((getx()-1==x)&&(gety()-1==y)))&&(getcolor()==w))
    {
        if(search(x,y)==b)
            return true;

        return false;
    }
    if((((getx()+1==x)&&(gety()-1==y))||((getx()+1==x)&&(gety()+1==y)))&&(getcolor()==b))
    {
        if(search(x,y)==w)
            return true;

        return false;
    }




    if (firstMove)
    {
        if(((abs( getx()- x))==2)&&(y==gety()))
        {

            if((getcolor()==w)&&((search(getx()- 2,gety())!="NONE")||(search(getx()- 1,gety())!="NONE")))
                return false;

            if((getcolor()==b)&&((search(getx()+ 2,gety())!="NONE")||(search(getx()+ 1,gety())!="NONE")))
                return false;

firstMove=false;
            return true;

        }
    }


if(((abs( getx()- x))==1)&&(y==gety()))
{
    if((getcolor()==w)&&(search(getx()- 1,gety())!="NONE"))
        return false;

    if((getcolor()==b)&&(search(getx()+ 1,gety())!="NONE"))
        return false;

    firstMove= false;
    return true;
}

return false;
}
QString Pawn::kind()
{
    return "Pawn";
}
