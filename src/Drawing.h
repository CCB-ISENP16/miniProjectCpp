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
  
  void drawAFigure(Figure figure, Point place);
  void draw();
  bool addStockage(Figure &figure,Point &place);
  void drawInTerminal(bool list);
private:
  void clearImage();
  void createTestImage();
  

private:
  const int width;
  const int height;

  std::vector<Point> placeList;
  std::vector<Figure> figList;
  std::vector<unsigned char> image;
};

#endif /* DRAWIN_H */