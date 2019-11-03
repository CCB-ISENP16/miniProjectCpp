#ifndef FIGCROSS_H
#define FIGCROSS_H

#include "Figure.h"
#include "Point.h"


class Cross : public Figure {
public:
  Cross(const int width, const int height);

  void draw() const ;
};

#endif