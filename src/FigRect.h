#ifndef RECT_H
#define RECT_H

#include "Point.h"
#include "Segment.h"
#include "Figure.h"
#include "Point.h"

class Rect : public Figure
{
public:
  Rect(const int width, const int height, const float thickness = 1.0, const int value = 255);
  void draw() const;
};

#endif /* RECT_H */