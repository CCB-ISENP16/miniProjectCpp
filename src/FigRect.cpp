#include "FigRect.h"
#include <iostream>

  Rect::Rect(const int width, const int height) : Figure(width, height) {
    Point pointHautGauche(0, 0);
    Point pointHautDroit(width - 1, 0);
    Point pointBasGauche(0, height - 1);
    Point pointBasDroit(width - 1, height - 1);

    drawSegment(Segment(pointHautGauche, pointHautDroit));
    drawSegment(Segment(pointHautDroit, pointBasDroit));
    drawSegment(Segment(pointBasDroit, pointBasGauche));
    drawSegment(Segment(pointBasGauche, pointHautGauche));
    // drawSegment(Segment(pointHautDroit, pointBasGauche));
    // drawSegment(Segment(pointHautGauche, pointBasDroit));
  }

  void Rect::draw() const {
    std::cout << "Affichage d'un rectangle : " << std::endl << std::endl;
    Figure::draw();
  }
