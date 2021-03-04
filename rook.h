#ifndef ROOK_H
#define ROOK_H
#include "figure.h"


class Rook:public figure
{
public:
    Rook(QString ,QGraphicsItem *parent = 0);
    void setpic();
    bool can_move(int x,int y);
    QString kind();

};

#endif // ROOK_H
