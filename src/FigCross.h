#ifndef FIGCROSS_H
#define FIGCROSS_H

#include "Figure.h"


class Cross : public Figure {
public:
  Cross(const int width, const int height) : Figure(width, height) {}

  void draw() const ;
};

#endif