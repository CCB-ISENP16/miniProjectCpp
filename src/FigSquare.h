#ifndef FIGSQUARE_H
#define FIGSQUARE_H

#include "FigRect.h"

class Carre : public Rect
{
public:
  Carre(const int size, const float thickness = 1.0, const int value = 255);
  ~Carre();

  void draw() const;
};

#endif