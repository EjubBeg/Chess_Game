#ifndef KNIGTH_H
#define KNIGTH_H
#include "figure.h"


class Knigth:public figure
{
public:
    Knigth(QString ,QGraphicsItem *parent = 0);
    void setpic();
    bool can_move(int x,int y);
    QString kind();

};

#endif // KNIGTH_H
