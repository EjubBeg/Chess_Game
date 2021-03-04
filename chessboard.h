#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "game.h"
#include "button.h"
#include "figure.h"
#include "singlesquare.h"
#include <QBrush>
#include <QGraphicsRectItem>

//Will make the chessboard in game class

class chessboard
{
public:
    chessboard();
    ~chessboard();
    //Makes the scene
    void make_board_scene();
    //Makes the figures
    void set_board();
    //Adds teh figures tho the squares
    void add_figures_to_game();
    //Function wich returns pointer of king of wanted color
    figure* get_king(QString);
    //If a pawn reaches the last square it transforms it to a queen
    void pawn_to_queen();
    //Returns the the type of chosen figure to move
    QString get_curr_kind();

    bool checkmate(QString);
    //Returns the opposite figure which attacks the king
    figure* find_problem(QString);

    bool check(QString);
    //function searches for possible attacks on king
    bool search_enemy(int ,int );
    //Changes the color of square of king is check is real
    void color_red(QString);
    //Returns the normal color
    void decolor(QString);
    QList <figure *> white_figures;
    QList <figure *> black_figures;
    singlesquare *squares[8][8];

private:
    QBrush brush;
};

#endif // CHESSBOARD_H
