#include "FigCross.h"


  Cross::Cross(const int width, const int height) : Figure(width, height) {
    drawSegment(Segment(Point(width / 2, 0), Point(width / 2, height - 1)));
    drawSegment(Segment(Point(0, height / 2), Point(width - 1, height / 2)));
  }

  void Cross::draw() const {
    std::cout << "Affichage d'une croix : " << std::endl << std::endl;
    Figure::draw();
  }
