#ifndef QUEEN_H
#define QUEEN_H
#include "figure.h"


class Queen:public figure
{
public:
    Queen(QString ,QGraphicsItem *parent = 0);
    void setpic();
    bool can_move(int x,int y);
    QString kind();

};

#endif // QUEEN_H
