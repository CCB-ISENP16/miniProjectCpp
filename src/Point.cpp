#include "Point.h"

  Point::Point(const float x0, const float y0) {
    x = x0;
    y = y0;
  }

  float Point::getX() const { return x; }
  float Point::getY() const { return y; }

  void Point::setX(float nx) { x = nx; }
  void Point::setY(float ny) { y = ny; }
