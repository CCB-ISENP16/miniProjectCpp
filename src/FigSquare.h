#ifndef FIGSQUARE_H
#define FIGSQUARE_H

#include "FigRect.h"


class Carre : public Rect {
public:
  Carre(const int size);
  ~Carre();

  void draw() const ;
};

#endif