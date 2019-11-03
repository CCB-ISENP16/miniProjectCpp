#ifndef MENU_H
#define MENU_H
#include "Drawing.h"

class Menu
{
    public:
    Menu();
    ~Menu();
    void run ();
    void save();
    void quit();

private:
    int choose, width, height, figure, widthf, heightf, X, Y;
    char FicName[70];

};
#endif