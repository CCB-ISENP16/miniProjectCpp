#include "FigTriangle.h"
#include <iostream>

Triangle::Triangle(const int width, const int height) : Figure(width, height)
{

    Point pointHautGauche(0, 0);
    Point pointHautDroit(width - 1, 0);
    Point pointBasGauche(0, height - 1);
    Point pointBasDroit(width - 1, height - 1);

    drawSegment(Segment(pointHautGauche, pointHautDroit));
    drawSegment(Segment(pointHautGauche, pointBasGauche));
    drawSegment(Segment(pointHautGauche, pointBasDroit));




    // Point pointBasGauche(0, 0);  FLECHE
    // Point pointHautGauche(0, height - 1);  FLECHE
    // Point pointHautDroit(width - 1, 0);   FLECHE

    // drawSegment(Segment(pointBasGauche, pointHautGauche)); FLECHE
    // drawSegment(Segment(pointBasGauche, pointHautDroit)); FLECHE
    // drawSegment(Segment(pointHautDroit, pointHautGauche));FLECHE
}

void Triangle::draw() const
{
    std::cout << "Affichage d'un triangle : " << std::endl
              << std::endl;
    Figure::draw();
}

Triangle::~Triangle()
{
}