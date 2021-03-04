#ifndef BISHOP_H
#define BISHOP_H
#include "figure.h"

class Bishop:public figure
{
public:
    Bishop(QString ,QGraphicsItem *parent = 0);
    void setpic();
    bool can_move(int x,int y);
     QString kind();

};

#endif // BISHOP_H
