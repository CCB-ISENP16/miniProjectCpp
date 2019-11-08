#include "FigSquare.h"

// @brief constructor of the class Square 
// @param width height int for width height of the Square
Carre::Carre(const int size,const int thickness) : Rect(size, size,thickness) {}
Carre::~Carre(){};

// @brief draw is the function for draw the figure in the ternimal 
// @param NULL
// @return NULL
void Carre::draw() const
{
  std::cout << "Affichage d'un carré : " << std::endl
            << std::endl;
  Figure::draw();
}