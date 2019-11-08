#include "FigRect.h"
#include <iostream>

// @brief constructor of the class Rect
// @param width height int for width height of the Rect
Rect::Rect(const int width, const int height, const float thickness, const int value) : Figure(width, height)
{
  Point pointHautGauche(0, 0);
  Point pointHautDroit(width - 1, 0);
  Point pointBasGauche(0, height - 1);
  Point pointBasDroit(width - 1, height - 1);

  drawSegment(Segment(pointHautGauche, pointHautDroit), thickness, value);
  drawSegment(Segment(pointHautDroit, pointBasDroit), thickness, value);
  drawSegment(Segment(pointBasDroit, pointBasGauche), thickness, value);
  drawSegment(Segment(pointBasGauche, pointHautGauche), thickness, value);
}
// @brief draw is the function for draw the figure in the ternimal
// @param NULL
// @return NULL
void Rect::draw() const
{
  std::cout << "Affichage d'un rectangle : " << std::endl
            << std::endl;
  Figure::draw();
}

int Rect::getType() const
{
  return type;
}
