#include "singlesquare.h"
#include "game.h"

extern Game *game;

singlesquare::singlesquare(QGraphicsItem *parent)
    :QGraphicsRectItem(parent)
{
        setRect(0,0,100,100);
        brush.setStyle(Qt::SolidPattern);
        setZValue(-1);
        currentfigure= nullptr;

}

singlesquare::~singlesquare()
{delete this;}



void singlesquare::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    game->turndisplayer->setPlainText(game->turn);
    game->Movedispalyer->setPlainText("Last Move");

        if(game->chosen_figure)
    {

       if(game->chosen_figure==currentfigure)
       {

           game->chosen_figure=nullptr;
           return;
       }
       if(game->chosen_figure->getcolor()==get_figure_color())
       {
           return;
       }
       if(game->chosen_figure->can_move(x_coord,y_coord))
       {



       if(has_figure())
       {
           replace(game->chosen_figure);
           game->move->setPlainText(game->chosen_figure->kind()+" has eaten a "+currentfigure->kind());

       }
       else
       {
           place(game->chosen_figure);
           game->move->setPlainText(game->chosen_figure->kind()+" has been moved");

       }


       game->chosen_figure=nullptr;
       game->myboard->pawn_to_queen();
       }
    }
     else
        {
            if(currentfigure==nullptr)
            {
                return;
            }

            if(currentfigure->getcolor()!=game->turn)
            {
                return;

            }

            game->chosen_figure = currentfigure;
            return;
        }


    }
void singlesquare::setColor(QColor color)
{
    orginal=color;
        brush.setColor(orginal);
        setBrush(orginal);
}
void singlesquare::add_figure(figure* f)
{

    f->setPos(x()+50 - f->pixmap().width()/2  ,y()+50-f->pixmap().width()/2);
    f->setsquare(this);
    currentfigure= f;
}
QString singlesquare::get_figure_color()
{
    if(currentfigure)
        return currentfigure->getcolor();

    return "NONE";

}
bool singlesquare::ishorizontal_vertical(int x,int y )
{
    if((x_coord==x)||(y==y_coord))
        return true;
    return false;
}
bool singlesquare::isdiagonal(int x,int y)
{
    if((abs(x-x_coord))==(abs(y-y_coord)))
        return true;
    return false;
}

//When we dont have a figure in square ,need to delete in old square
void singlesquare::place(figure *f)
{
    f->currentBox->currentfigure=nullptr;
    add_figure(f);

    f->firstMove=false;
    changeturn();

}
//Here we have a
void singlesquare::replace(figure *f)
{
currentfigure->currentBox=nullptr;
game->place_dead(currentfigure);
place(f);
}
void singlesquare::set_x_y(int x,int y)
{
     x_coord=x;
     y_coord=y;
}
bool singlesquare::has_figure()
{
    if(currentfigure==nullptr)
        return false;

    return true;

}
void singlesquare::castling(int cases)
{

if(cases==1)
{
    game->myboard->squares[0][4]->currentfigure->firstMove=false;
    game->myboard->squares[0][0]->currentfigure->firstMove=false;

game->myboard->squares[0][2]->place(game->myboard->squares[0][4]->currentfigure);
game->myboard->squares[0][3]->place(game->myboard->squares[0][0]->currentfigure);

}
else if(cases==2)
{
    game->myboard->squares[0][4]->currentfigure->firstMove=false;
    game->myboard->squares[0][7]->currentfigure->firstMove=false;
    game->myboard->squares[0][6]->place(game->myboard->squares[0][4]->currentfigure);
    game->myboard->squares[0][5]->place(game->myboard->squares[0][7]->currentfigure);

}
else if(cases==3)
{
    game->myboard->squares[7][4]->currentfigure->firstMove=false;
    game->myboard->squares[7][0]->currentfigure->firstMove=false;
    game->myboard->squares[7][2]->place(game->myboard->squares[7][4]->currentfigure);
    game->myboard->squares[7][3]->place(game->myboard->squares[7][0]->currentfigure);

}
else
{
    game->myboard->squares[7][4]->currentfigure->firstMove=false;
    game->myboard->squares[7][7]->currentfigure->firstMove=false;
    game->myboard->squares[7][6]->place(game->myboard->squares[7][4]->currentfigure);
    game->myboard->squares[7][5]->place(game->myboard->squares[7][7]->currentfigure);

}
changeturn();
}

void singlesquare::changeturn()
{
 QString b ="BLACK";
 QString w ="WHITE";

    if(!(game->myboard->check(game->turn)))
    game->myboard->decolor(game->turn);

    if(game->turn==w)
    {
        game->turn=b;
        game->turndisplayer->setPlainText(game->turn);

    }
    else
    {
        game->turn=w;
        game->turndisplayer->setPlainText(game->turn);
    }

    //if user can stop second check it will me checkmate
    if(game->turn==b)
    {
        if(game->myboard->check(w))
        {
            game->winner=game->player2name;
            game->exit();
        }
    }
    if(game->turn==w)
    {
        if(game->myboard->check(b))
        {
            game->winner=game->player1name;
            game->exit();
        }
    }


if(game->myboard->check(game->turn))
    {
     game->myboard->color_red(game->turn);

     //I wanted to implement better solution for
     //checkmate and there are all function ,but unfortunetlly
     //i doesnt work well


     /*if(game->myboard->checkmate(game->turn))
                {
                  if(game->turn=="WHITE")
                      game->winner=game->player2name;
                  else
                      game->winner=game->player1name;

                    game->exit();

                }*/

    }



    }


QString singlesquare::get_fig_kind()
{
if(currentfigure==nullptr)
    return "NONE";

return currentfigure->kind();
}

//Here we have a
void singlesquare::replacepawn(figure *f)
{
game->scene->addItem(f);
game->add_to_cur_items(f);
currentfigure->currentBox=nullptr;
game->delete_single(currentfigure);
add_figure(f);
f->firstMove=false;
}
void singlesquare::second_color(QColor color)
{
    brush.setColor(color);
    setBrush(color);
}
void singlesquare::return_color()
{
    brush.setColor(orginal);
    setBrush(orginal);
}

bool singlesquare::isAttacked(QString s)
{
    for(int i= 0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if((game->myboard->squares[i][j]->get_figure_color()!=s)&&(game->myboard->squares[i][j]->has_figure()))
            {
                if(game->myboard->squares[i][j]->currentfigure->can_move(x_coord,y_coord))
                    return true;
            }
        }

    }
    return false;
}
bool singlesquare::block_ver_hor(int x, int y)
{


    if(x_coord==x)
    {
    if(y>y_coord)
    {
        --y;
    while(y_coord != y)
    {
    if(game->myboard->squares[x][y]->isAttacked(get_fig_kind()))
        return true;
    y--;
    }
    return false;
    }
    else
    {
        ++y;
    while(y_coord != y)
    {
        if(game->myboard->squares[x][y]->isAttacked(get_fig_kind()))
            return true;
    y++;
    }

    return false;
    }
    }
    else
    {
    if(x>x_coord)
    {
        --x;
    while(x_coord != x)
    {
        if(game->myboard->squares[x][y]->isAttacked(get_fig_kind()))
            return true;
    x--;
    }
    return false;

    }
    else
    {
        ++x;
    while(x_coord != x)
    {
        if(game->myboard->squares[x][y]->isAttacked(get_fig_kind()))
            return true;
    x++;
    }
    return false;
    }
    }

}
bool singlesquare::block_diagonal(int x, int y)
{
    if(x>x_coord&&y>y_coord)
    {
    --x;
    --y;
    while(x_coord!=x)
    {
        if(game->myboard->squares[x][y]->isAttacked(get_fig_kind()))
            return true;
    --x;
    --y;
    }
    return false;

    }
    else if(x<x_coord&&y>y_coord)
    {
        ++x;
        --y;
        while(x_coord!=x)
        {
            if(game->myboard->squares[x][y]->isAttacked(get_fig_kind()))
                return true;
        ++x;
        --y;
        }
        return false;

    }
    else if(x<x_coord&&y<y_coord)
    {
        ++x;
        ++y;
        while(x_coord!=x)
        {
            if(game->myboard->squares[x][y]->isAttacked(get_fig_kind()))
                return true;
        ++x;
        ++y;
        }
        return false;

    }
    else
    {
        --x;
        ++y;
        while(x_coord!=x)
        {
            if(game->myboard->squares[x][y]->isAttacked(get_fig_kind()))
                return true;
        --x;
        ++y;
        }
        return false;

    }
}
