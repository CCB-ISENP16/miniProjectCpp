#include "FigSquare.h" 


 Carre::Carre(const int size) : Rect(size, size) {}

  void Carre::draw() const {
    std::cout << "Affichage d'un carré : " << std::endl << std::endl;
    Figure::draw();
  }