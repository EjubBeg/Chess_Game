#ifndef KING_H
#define KING_H
#include "figure.h"


class King:public figure
{
public:
    King(QString ,QGraphicsItem *parent = 0);
    void setpic();
    bool can_move(int x,int y);
    QString kind();


};

#endif // KING_H
