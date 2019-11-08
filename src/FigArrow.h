#ifndef FIGARROW_H
#define FIGARROW_H

#include "Point.h"
#include "Segment.h"
#include "Figure.h"
#include "Point.h"

class Arrow : public Figure
{
private:
    /* data */
public:
    Arrow(const int width, const int height,const float thickness=1);
    void draw() const;
    ~Arrow();
};

#endif