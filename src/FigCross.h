#ifndef FIGCROSS_H
#define FIGCROSS_H

#include "Figure.h"
#include "Point.h"

class Cross : public Figure
{
public:
  Cross(const int width, const int height, const float thickness = 1.0, const int value = 255);
  ~Cross();

  void draw() const;
};

#endif