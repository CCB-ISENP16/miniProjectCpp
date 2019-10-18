#ifndef POINT_H
#define POINT_H

class Point {
public:
  Point(const float x0, const float y0);

  float getX() const;
  float getY() const;

  void setX(float nx) ;
  void setY(float ny) ;

private:
  float x, y;
};

#endif /* POINT_H */