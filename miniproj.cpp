#include <iostream>
#include <string>

#include "Drawing.h"
#include "Figure.h"

const int width = 300;
const int height = 400;

int main(int argc, char **argv) {

  Drawing draw(width, height);

  //draw.save(std::string("test_image.bmp"));

  Figure figure(10,10);
  Point place (1,1);
  draw.draw(figure,place);
  draw.save(std::string("test_image.bmp"));

  

  return 0;
}