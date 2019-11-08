#include "FigArrow.h"

Arrow::Arrow(const int width, const int height,const float thickness) : Figure(width, height)
{
    Point pointBasGauche(0, 0);
    Point pointHautGauche(0, height - 1);
    Point pointHautDroit(width - 1, 0);

    drawSegment(Segment(pointBasGauche, pointHautGauche),thickness);
    drawSegment(Segment(pointBasGauche, pointHautDroit),thickness);
    drawSegment(Segment(pointHautDroit, pointHautGauche),thickness);
}

void Arrow::draw() const
{
    std::cout << "Affichage d'une fleche : " << std::endl
              << std::endl;
    Figure::draw();
}

Arrow::~Arrow()
{
}