#include <iostream>
#include <string>

#include "Drawing.h"
#include "Figure.h"
#include "Point.h"
#include "FigSquare.h"
#include "Menu.h"

const int width = 30;
const int height = 40;

int main(int argc, char **argv)
{
  system("clear");
  Menu menu;
  menu.run();

  return 0;
}