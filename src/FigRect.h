#ifndef RECT_H
#define RECT_H

#include "Figure.h"

class Rect : public Figure {
public:
  Rect(const int width, const int height) : Figure(width, height){}
  void draw() const;
};

#endif /* RECT_H */