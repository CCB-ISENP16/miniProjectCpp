#include <iostream>
#include <string>

#include "Drawing.h"
#include "Figure.h"
#include "Point.h"
#include "FigSquare.h"
#include "Menu.h"

const int width = 30;
const int height = 40;

int main(int argc, char **argv) {

  Drawing draw(width, height);
  Figure figure(10,10);
  Carre square(10);
  Rect rect(10,20);
  Point place (15,20);
  
  draw.addStockage(rect,place);
  printf("test\n");
  draw.save(std::string("image.bmp"));

  Menu menu;
  menu.run();
  

  return 0;
}