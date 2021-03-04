#ifndef SINGLESQUARE_H
#define SINGLESQUARE_H
#include <cmath>
#include "figure.h"
#include "QGraphicsRectItem"
#include <QBrush>
#include <QGraphicsSceneMouseEvent>


class figure;

class singlesquare:public QGraphicsRectItem
{
public:
    singlesquare(QGraphicsItem *parent=0);
    ~singlesquare();
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void setColor(QColor color);
    //Used for check to show that user the king is attacked
    void second_color(QColor color);
    //Chenges the color of the square to its original
    void return_color();
    //Checkes can a opposite figure attack that square
    bool isAttacked(QString);
    //Ads figure to square
    void add_figure(figure* f);
    //Returns color of figuure on square
    QString get_figure_color();

    bool has_figure();
    //Returns type of figure
    QString get_fig_kind();
    //Used for replacing pawn with queen
    void replacepawn(figure *f);
    //Checks is the line horizontal or vertical
    bool ishorizontal_vertical(int x,int y);
    //Checks can the king be blocked
    bool block_diagonal(int ,int );
    //Checks can the king be blocked
    bool block_ver_hor(int,int);
    //Checks is the line diagonal
    bool isdiagonal(int x,int y);
    //Places figure on square
    void place(figure*);
    //Replaces figure with other figure
    void replace(figure*);
    void set_x_y(int ,int );
    void castling(int);
    int x_coord;
    int y_coord;
    void changeturn();
    QColor orginal;
    figure * currentfigure;
private:
    QBrush brush;

};

#endif
