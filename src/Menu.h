#ifndef MENU_H
#define MENU_H
#include "Drawing.h"
#include "Drawing.h"
#include "FigSquare.h"
#include "FigCross.h"
#include "FigRect.h"
#include "Point.h"
#include "string.h"
#include "FigTriangle.h"
#include "FigArrow.h"

class Menu
{
public:
    Menu();
    ~Menu();
    void run();
    void save();
    void quit();

private:
    int choose, width, height, figure, widthf, heightf, X, Y, Intensity, Thinkness;
    char FicName[70];
    Point * place1;
    Triangle * triangle;
    Arrow * arrow;
    Rect * rect;
    Cross *  cross;
    Carre * square;
};
#endif