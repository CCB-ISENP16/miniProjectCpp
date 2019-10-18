#include "Segment.h"

/* dans la liste d'initialisation, appel des constructeurs des objets membres
org et ext
1ere version : pour org et ext, appel du constructeur Point(int,int)
2eme version : pour org et ext, appel du constructeur par copie de Point
*/
Segment::Segment(const Point &a, const Point &b)
    : org(a.getX(), a.getY()), ext(b.getX(), b.getY())
//: org(a), ext(b)    // 2eme version
{}

void Segment::translation(const Point &nouvOrg) {
  // calcul des déplacements sur x et sur y
  float dx = nouvOrg.getX() - org.getX();
  float dy = nouvOrg.getY() - org.getY();

  org.setX(nouvOrg.getX());
  org.setY(nouvOrg.getY());

  ext.setX(ext.getX() + dx);
  ext.setY(ext.getY() + dy);

  /* si setX et setY n'existaient pas, on aurait pu modifier org et ext
   * ainsi :
  org = nouvOrg;
  Point nouvExt (ext.getX() + dx, ext.getY() + dy);
  ext = nouvExt;
  */
}

void Segment::afficher() const {
  std::cout << "origine(" << org.getX() << "," << org.getY() << ")"
            << ", extremite(" << ext.getX() << "," << ext.getY() << ")"
            << std::endl;
}

Point Segment::getOrigin() const { return org; }

Point Segment::getDest() const { return ext; }