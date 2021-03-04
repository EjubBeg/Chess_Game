#include "chessboard.h"
#include "pawn.h"
#include "figure.h"
#include "king.h"
#include "queen.h"
#include "knigth.h"
#include "rook.h"
#include "bishop.h"

extern Game* game;

chessboard::chessboard()
{

}
chessboard::~chessboard()
{
    delete this;
}

void chessboard::set_board(){

    for(int i = 0; i < 8; i++) {
        white_figures.append(new Pawn("WHITE"));
    }
    white_figures.append(new Rook("WHITE"));
    white_figures.append(new Knigth("WHITE"));
    white_figures.append(new Bishop("WHITE"));
    white_figures.append(new Queen("WHITE"));
    white_figures.append(new King("WHITE"));
    white_figures.append(new Bishop("WHITE"));
    white_figures.append(new Knigth("WHITE"));
    white_figures.append(new Rook("WHITE"));


    black_figures.append(new Rook("BLACK"));
    black_figures.append(new Knigth("BLACK"));
    black_figures.append(new Bishop("BLACK"));
    black_figures.append(new Queen("BLACK"));
    black_figures.append(new King("BLACK"));
    black_figures.append( new Bishop("BLACK"));
    black_figures.append(new Knigth("BLACK"));
    black_figures.append(new Rook("BLACK"));

    for(int i = 0; i < 8; i++) {
        black_figures.append(new Pawn("BLACK"));
    }


    }

void chessboard::make_board_scene()
{
    int SHIFT = 100;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
        {
            squares[i][j]=new singlesquare();
            squares[i][j]->set_x_y(i,j);
            squares[i][j]->setPos(400+SHIFT*j,50+SHIFT*i);
            if((i+j)%2==0)
                squares[i][j]->setColor(Qt::white);
            else
                squares[i][j]->setColor(Qt::darkGray);

            game->add_to_cur_items(squares[i][j]);
            game->scene->addItem(squares[i][j]);

        }
    }
}

void chessboard::add_figures_to_game()
{
int w= 0;
int b= 0;
for(int i = 0; i < 8; i++) {
for(int y = 0; y < 8; y++){
if(i < 2) {
squares[i][y]->add_figure(black_figures[b]);
game->scene->addItem(black_figures[b]);
game->add_to_cur_items(black_figures[b]);
b++;}
if(i > 5) {
 squares[i][y]->add_figure(white_figures[w]);
game->scene->addItem(white_figures[w]);
game->add_to_cur_items(white_figures[w]);
w++;
}}}}

void chessboard::pawn_to_queen()
{
for(int i= 0;i<8;i++)
{
if(squares[7][i]->get_fig_kind()=="Pawn")
    squares[7][i]->replacepawn(new Queen("BLACK"));

if(squares[0][i]->get_fig_kind()=="Pawn")
    squares[0][i]->replacepawn(new Queen("WHITE"));


}

}
QString chessboard::get_curr_kind()
{
 if(game->chosen_figure==nullptr)
     return "NONE";

 return game->chosen_figure->kind();
}

bool chessboard::check(QString c)
{
figure* king;
for(int i= 0;i<8;i++)
{
    for(int j=0;j<8;j++)
    {
    if((squares[i][j]->get_fig_kind()=="King")&&(squares[i][j]->get_figure_color()==c))
    {
     king=squares[i][j]->currentfigure;
    }
    }
}
int x= king->getx();
int y= king->gety();
return (search_enemy(x,y));
}
bool chessboard::search_enemy(int x,int y)
{
figure* king = squares[x][y]->currentfigure;
 for(int i= 0;i<8;i++)
 {
     for(int j=0;j<8;j++)
     {
         if((squares[i][j]->get_figure_color()!=king->getcolor())&&(squares[i][j]->has_figure()))
         {
             if(squares[i][j]->currentfigure->can_move(x,y))
                 return true;
         }

     }
 }
 return false;
}

void chessboard::color_red(QString s)
{
    for(int i= 0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if((squares[i][j]->get_figure_color()==s)&&(squares[i][j]->get_fig_kind()=="King"))
            {
                squares[i][j]->second_color(Qt::red);
            }
        }
    }


}
void chessboard::decolor(QString s)
{
    for(int i= 0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
                squares[i][j]->return_color();
        }
    }

}


bool chessboard::checkmate(QString s)
{
figure* king = get_king(s);

for(int i=king->getx()-1;i<king->getx()+2;i++)
{
for(int j=king->gety()-1;j<king->gety()+2;j++)
{
 if((i==king->getx())&&(j==king->gety()))
     continue;

if((i<0||i>7)&&(j<0||j>7))
    continue;

if(((squares[i][j]->get_figure_color()==s)||(squares[i][j]->isAttacked(s))))
    return false;
}
}
figure* enemy = find_problem(s);
for(int i=king->getx()-1;i<king->getx()+2;i++)
{
for(int j=king->gety()-1;j<king->gety()+2;j++)
{
    if((i<0||i>7)&&(j<0||j>7))
        continue;

if((squares[i][j]->get_figure_color()==s)&&(squares[i][j]->has_figure()))
if(squares[i][j]->currentfigure->can_move(enemy->getx(),enemy->gety()))
    return false;
}
}
int ex=enemy->getx();
int ey=enemy->gety();
if(king->currentBox->isdiagonal(ex,ey))
{
 if(king->currentBox->block_diagonal(ex,ey));
 return false;

}
if(king->currentBox->ishorizontal_vertical(ex,ey))
{
    if(king->currentBox->block_ver_hor(ex,ey));
    return false;
}

return false;

}
figure* chessboard::get_king(QString s)
{
    for(int i= 0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if((game->myboard->squares[i][j]->get_figure_color()==s)&&(game->myboard->squares[i][j]->get_fig_kind()=="King"))
            {
                return game->myboard->squares[i][j]->currentfigure;
            }
        }
    }

}

figure* chessboard::find_problem(QString s)
{
figure* king= get_king(s);
    int x= king->getx();
    int y= king->gety();

for(int i= 0;i<8;i++)
{
    for(int j=0;j<8;j++)
    {
        if((game->myboard->squares[i][j]->get_figure_color()!=s)&&(game->myboard->squares[i][j]->has_figure()))
        {
            if(game->myboard->squares[i][j]->currentfigure->can_move(x,y))
                return game->myboard->squares[i][j]->currentfigure;        }
    }
}
}


