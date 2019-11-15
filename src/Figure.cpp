#include "Figure.h"

Figure::Figure(const int width, const int height) : width(width), height(height)
{
    buffer.resize(width * height);
    clearBuffer();
}

// Déconstructeur de la figure
Figure::~Figure()
{
    if (!buffer.empty())
    {
        buffer.clear(); // Si le buffer n'est pas vide on le vide avec la fonction clear
    }
}

char Figure::getData(int place) const
{
    return buffer.at(place); // Retourne la donnée du buffer a la place voulu
}

void Figure::clearBuffer()
{
    std::vector<unsigned char>::iterator it;
    for (it = buffer.begin(); it != buffer.end(); it++)
    {
        *it = 0; // non reinitialise le buffer a 0
    }
}

bool Figure::setPoint(const int col, const int line, const int value)
{
    if (col < 0 || col >= width || line < 0 || line >= height)
    {
        return false; // gestion en cas de débordement
    }
    buffer.at(col + width * line) = value; // on donne a chaque case du buffer la couleur que l'on veut (0-255)
    return true;                           // retourne Vrai pour indiquer que tout s'est bien passé
}

bool Figure::clearPoint(const int col, const int line)
{
    if (col < 0 || col >= width || line < 0 || line >= height)
    {
        return false; // gestion en cas de débordement
    }
    buffer.at(line * width + col) = 0; // Initilisation d'un pixel a 0 pour "effacer"
    return true;
}

void Figure::draw() const
{
    for (int line = 0; line < height; line++)
    {
        for (int col = 0; col < width; col++)
        {
            std::cout << buffer[line * width + col] << " "; // Affichage de la figure sur le terminal
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Figure::drawPoint(const Point &point, const float thickness, const int value)
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
                setPoint(col, line, value);
            }
        }
    }
}

void Figure::drawSegment(const Segment &segment, const float thickness, const int value)
{

    Point point1 = (segment.getDest().getX() < segment.getOrigin().getX())
                       ? segment.getDest()
                       : segment.getOrigin();

    Point point2 = (point1.getX() == segment.getDest().getX())
                       ? segment.getOrigin()
                       : segment.getDest();

    float dx = point1.getX() - point2.getX();
    float dy = point1.getY() - point2.getY();

    for (int x = point1.getX(); x <= point2.getX(); x++)
    {
        for (int y = 0; y < height; y++)
        {
            float dist;

            if ((dx == 0) ||
                (fabs((float)y - (float)point1.getY() -
                      (float)dy * (float)(x + point1.getX()) /
                          (float)dx) < 1))
            {
                drawPoint(Point(x, y), thickness, value);
            }
        }
    }
}

// @brief This function is called a "getter" it return the variable height which is private
// @param NULL
// @return height
int Figure::getHeight() const
{
    return height; // permet de recuperer la height en dehors de la classe car c'est une variable privé
}

// @brief This function is called a "getter" it return the variable width which is private
// @param NULL
// @return width
int Figure::getWidth() const
{
    return width; // permet de recuperer la width en dehors de la classe car c'est une variable privé
}

// @brief This function is called a "getter" it return the variable "figure" which is private
// @param NULL
// @return figure
int Figure::getType() const
{
    return figure; // permet de recuperer la figure en dehors de la classe car c'est une variable privé
}