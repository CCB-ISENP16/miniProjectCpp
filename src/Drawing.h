#ifndef DRAWING_H
#define DRAWING_H

#include <string>
#include <vector>
#include "Figure.h"

class Drawing
{
public:
  Drawing(const int width, const int height);
  ~Drawing();

  void save(std::string filename);
  
  void draw(Figure figure, Point place);

private:
  void clearImage();
  void createTestImage();
  bool addStockage(Figure figure,Point place);

private:
  const int width;
  const int height;

  std::vector<Point> placeList;
  std::vector<Figure> figList;
  std::vector<char> image;
};

#endif /* DRAWIN_H */