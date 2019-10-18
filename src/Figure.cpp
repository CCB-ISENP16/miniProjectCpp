#include "Figure.h"


Figure::Figure(const int width, const int height) : width(width), height(height)
{
    buffer.resize(width * height);
    clearBuffer();
}

Figure::~Figure()
{
    if (!buffer.empty())
    {
        buffer.clear();
    }
}

char Figure::getData(int place) const
{
    return buffer.at(place);
}

// set all pixel to 0
void Figure::clearBuffer()
{
    std::vector<char>::iterator it;
    for (it = buffer.begin(); it != buffer.end(); it++)
    {
        *it = 0;
    }
}

bool Figure::setPoint(const int col, const int line, const int value)
{
    if (col < 0 || col >= width || line < 0 || line >= height)
    {
        return false;
    }
    buffer.at(col * line) = value;
    return true;
}

bool Figure::setPoint(const int col, const int line)
{
    if (col < 0 || col >= width || line < 0 || line >= height)
    {
        return false;
    }
    buffer.at(col * line) = 255;
    return true;
}

bool Figure::createlineV(const int col, const int line, const int value)
{
    if (col < 0 || col >= width || line < 0 || line >= height)
    {
        return false;
    }
    for (int a = 0; a < line; a++)
    {
        setPoint(col, a, value);
    }
    return true;
}

bool Figure::createlineH(const int col, const int line, const int value)
{
    if (col < 0 || col >= width || line < 0 || line >= height)
    {
        return false;
    }
    for (int a = 0; a < col; a++)
    {
        setPoint(a, line, value);
    }
    return true;
}

bool Figure::clearPoint(const int col, const int line)
{
    if (col < 0 || col >= width || line < 0 || line >= height)
    {
        return false;
    }
    buffer.at(line * width + col) = 0;
    return true;
}

 void  Figure::draw() const
{
    for (int line = 0; line < height; line++)
    {
        for (int col = 0; col < width; col++)
        {
            std::cout << buffer[line * width + col] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Figure::drawPoint(const Point &point, const float thickness )
{
    for (int line = 0; line < height; line++)
    {
        for (int col = 0; col < width; col++)
        {
            /* Calcul de la distance entre le point décrit par (col, line) et le
         * point décrit par "point" */
            float squaredVertDistance =
                (line - point.getY()) * (line - point.getY());
            float squaredHorDistance = (col - point.getX()) * (col - point.getX());

            /* Si la distance est inférieure à l'épaisseur de point, on met le point
         */
            if (squaredVertDistance + squaredHorDistance < thickness * thickness)
            {
                setPoint(col, line);
            }
        }
    }
}

void Figure::drawSegment(const Segment &segment, const float thickness )
{

    /* Le point 1 est l'extrémité du segment le plus à gauche  */
    Point point1 = (segment.getDest().getX() < segment.getOrigin().getX())
                       ? segment.getDest()
                       : segment.getOrigin();

    /* Point2 est l'autre extrémité du segment */
    Point point2 = (point1.getX() == segment.getDest().getX())
                       ? segment.getOrigin()
                       : segment.getDest();

    /* Calcul des pentes */
    float dx = point1.getX() - point2.getX();
    float dy = point1.getY() - point2.getY();

    /* On parcourt les x sur l'ensemble du segment */
    for (int x = point1.getX(); x <= point2.getX(); x++)
    {
        /* On parcourt les y sur l'ensemble de la hauteur */
        for (int y = 0; y < height; y++)
        {
            float dist;
            /* Si le segment est vertical, toutes les coordonnées
                         parcourues sont bonnes */
            /* Sinon, on dessine un point du segment si les coordonnées sont
         * validées par l'equation de la droite */
            if ((dx == 0) ||
                (fabs((float)y - (float)segment.getOrigin().getY() +
                      (float)dy * (float)(x - segment.getDest().getX()) /
                          (float)dx) < 1))
            {
                drawPoint(Point(x, y), thickness);
            }
        }
    }
}

bool Figure::drawVertLine(const int col)
{
    if (col < 0 || col >= width)
    {
        return false;
    }

    for (int counter = 0; counter < height; counter++)
    {
        if (!setPoint(col, counter))
        {
            std::cout << "Unable to set point : [" << col << ", " << counter << "]"
                      << std::endl;
        }
    }
    return true;
}

bool Figure::drawHorLine(const int line)
{
    if (line < 0 || line >= height)
    {
        return false;
    }

    for (int counter = 0; counter < width; counter++)
    {
        if (!setPoint(counter, line))
        {
            std::cout << "Unable to set point : [" << counter << ", " << line << "]"
                      << std::endl;
        }
    }
    return true;
}

int Figure::getHeight()const {
    return height;
}

int Figure::getWidth() const {
    return width;
}