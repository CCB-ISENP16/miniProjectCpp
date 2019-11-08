#include "FigCross.h"

// @brief constructor of the class Cross
// @param width height int for width height of the Cross
Cross::Cross(const int width, const int height, const float thickness, const int value) : Figure(width, height)
{
  drawSegment(Segment(Point(width / 2, 0), Point(width / 2, height - 1)), thickness, value);
  drawSegment(Segment(Point(0, height / 2), Point(width - 1, height / 2)), thickness, value);
}
// the destructor
Cross::~Cross(){};

// @brief draw is the function for draw the figure in the ternimal
// @param NULL
// @return NULL
void Cross::draw() const
{
  std::cout << "Affichage d'une croix : " << std::endl
            << std::endl;
  Figure::draw();
}
