#include <iostream>
#include <string>

#include "Menu.h"
// @brief this is the main function who is call the start menu 
// menu is a class defined in Menu.cpp


int main(int argc, char **argv)
{
  system("clear");
  Menu menu;
  menu.run();

  return 0;
}