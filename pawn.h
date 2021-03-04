#ifndef PAWN_H
#define PAWN_H
#include "figure.h"


class Pawn:public figure
{
public:
    Pawn(QString ,QGraphicsItem *parent = 0);
    void setpic();
    bool can_move(int x,int y);
    QString kind();


};

#endif // PAWN_H
