#include "FigArrow.h"

Arrow::Arrow(const int width, const int height, const float thickness, const int value) : Figure(width, height)
{
  Point pointBasGauche(0, 0);                 // Définition du point d'origine
  Point pointHautGauche(0, height - 1);       //  définition du point en haut a gauche
  Point pointHautDroit(width - 1, 0);         // définition du point en haut a droite
  Point pointBasDroit(width - 1, height - 1); // définition du point en haut a droite

  drawSegment(Segment(pointBasGauche, pointHautGauche), thickness, value); // On relis les points par des segments pour creer la forme souhaité
  drawSegment(Segment(pointBasGauche, pointHautDroit), thickness, value);  // On relis les points par des segments pour creer la forme souhaité
  drawSegment(Segment(pointBasDroit, pointBasGauche), thickness, value); // On relis les points par des segments pour creer la forme souhaité
}

void Arrow::draw() const
{
  std::cout << "Affichage d'une fleche : " << std::endl // re implémentation de la fonction draw pour afficher le nom de la figure correspondante
            << std::endl;
  Figure::draw();
}

Arrow::~Arrow()
{
}

// @brief This function return the type of the figure in this case "Arrow"
// @param NULL
// @return type
int Arrow::getType() const
{
  return type;
}