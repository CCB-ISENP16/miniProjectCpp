#ifndef FIGSQUARE_H
#define FIGSQUARE_H

#include "FigRect.h"


class Carre : public Rect {
public:
  Carre(const int size,const int thickness=1);
  ~Carre();

  void draw() const ;
};

#endif