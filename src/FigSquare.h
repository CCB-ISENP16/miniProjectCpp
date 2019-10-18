#ifndef FIGSQUARE_H
#define FIGSQUARE_H

#include "FigRect.h"


class Carre : public Rect {
public:
  Carre(const int size) : Rect(size, size) {}

  void draw() const {
    std::cout << "Affichage d'un carré : " << std::endl << std::endl;
    Figure::draw();
  }
};

#endif