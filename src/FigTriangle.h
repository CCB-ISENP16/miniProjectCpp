#ifndef FIGTRIANGLE_H
#define FIGTRIANGLE_H

#include "Point.h"
#include "Segment.h"
#include "Figure.h"
#include "Point.h"

class Triangle : public Figure
{
public:
    Triangle(const int width, const int height);
    void draw() const;
    ~Triangle();
};

#endif