#include "figure.h"
#include "game.h"
#include "singlesquare.h"
extern Game *game;

figure::figure(QString f,QGraphicsItem *parent)
    :QGraphicsPixmapItem(parent),
     isPlaced(true),
     firstMove(true),
     figurecolor(f)
{
}
QString figure::searchkind(int x,int y)
{
  if(((x>7)||(x<0))||((y>7)||(y<0)))
      return "FALSE";

  return game->myboard->squares[x][y]->get_fig_kind();
}
QString figure::search(int x,int y)
{
  if(((x>7)||(x<0))||((y>7)||(y<0)))
      return "FALSE";

  return game->myboard->squares[x][y]->get_figure_color();
}

bool figure::isfirst_move(int x,int y)
{

    return game->myboard->squares[x][y]->currentfigure->firstMove;
}

void figure::setsquare(singlesquare * s)
{
    currentBox = s;
}

singlesquare* figure::getsquare()
{
    return currentBox;
}
QString figure::getcolor()
{
    return figurecolor;
}
void figure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    game->Movedispalyer->setPlainText("Figure");

    currentBox->mousePressEvent(event);
}

int figure::getx()
{
 return currentBox->x_coord;
}
int figure::gety()
{
return currentBox->y_coord;

}

bool figure::safe_hor_ver_root(int x,int y)
{
if(getx()==x)
{
if(y>gety())
{
    --y;
while(gety() != y)
{
if(search(x,y)!="NONE")
    return false;
y--;
}
return true;
}
else
{
    ++y;
while(gety() != y)
{
if(search(x,y)!="NONE")
    return false;
y++;
}

return true;
}
}
else
{
if(x>getx())
{
    --x;
while(getx() != x)
{
if(search(x,y)!="NONE")
    return false;
x--;
}
return true;

}
else
{
    ++x;
while(getx() != x)
{
if(search(x,y)!="NONE")
    return false;
x++;
}
return true;
}
}
}

bool figure::safe_dia_root(int x,int y)
{
if(x>getx()&&y>gety())
{
--x;
--y;
while(getx()!=x)
{
if(search(x,y)!="NONE")
    return false;
--x;
--y;
}
return true;

}
else if(x<getx()&&y>gety())
{
    ++x;
    --y;
    while(getx()!=x)
    {
    if(search(x,y)!="NONE")
        return false;
    ++x;
    --y;
    }
    return true;

}
else if(x<getx()&&y<gety())
{
    ++x;
    ++y;
    while(getx()!=x)
    {
    if(search(x,y)!="NONE")
        return false;
    ++x;
    ++y;
    }
    return true;

}
else
{
    --x;
    ++y;
    while(getx()!=x)
    {
    if(search(x,y)!="NONE")
        return false;
    --x;
    ++y;
    }
    return true;

}
}
void figure::kill_chosen()
{
    game->chosen_figure=nullptr;
}







