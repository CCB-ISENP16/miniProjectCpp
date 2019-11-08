#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Point.h"
#include "Segment.h"

class Figure
{
public:
    Figure(const int width, const int height);

    ~Figure();

    char getData(int place) const;
    int getHeight() const;
    int getWidth() const;

protected:
    void clearBuffer();

    bool setPoint(const int col, const int line, const int value = 255);

    // bool setPoint(const int col, const int line);

    bool clearPoint(const int col, const int line);

    virtual void draw() const;
    void drawPoint(const Point &point, const float thickness = 1.0, const int value = 255);
    void drawSegment(const Segment &segment, const float thickness = 1.0, const int value = 255);

private:
    std::vector<unsigned char> buffer;

    int width;
    int height;
};
#endif
