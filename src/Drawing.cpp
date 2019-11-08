#include "Drawing.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <stdexcept>

//            _    _  _                     _    _           _
//  ___  _ _ | |_ | |<_> ___  ._ _ _  ___ _| |_ | |_  ___  _| | ___
// | . \| | || . \| || |/ | ' | ' ' |/ ._> | |  | . |/ . \/ . |<_-<
// |  _/`___||___/|_||_|\_|_. |_|_|_|\___. |_|  |_|_|\___/\___|/__/
// |_|

// @brief the constructor of the area of draw 
// @param width is a int for the width of this area
// @param height is a int for the heigth of this area
// @return NULL
Drawing::Drawing(const int width, const int height)
    : width(width), height(height)
{
  image.resize(width * height);
}

// the destructor
Drawing::~Drawing() {}

/*@brief Save image to file "filename" */
// @param string filename the name you want 
void Drawing::save(std::string filename)
{

  if (filename.substr(filename.find_last_of(".") + 1) != "bmp")
  {
    throw std::runtime_error(
        "Drawing ne supporte que l'enregistrement d'images au format bmp");
  }
  draw();
  stbi_write_bmp(filename.c_str(), width, height, 1, image.data());
}

// @brief drawAFigure is the function to draw one figure at place you want   
// @param figure the param of the class Figure you want to draw
// @param place the param of the class Point is the place you want to draw
// @return NULL
void Drawing::drawAFigure(Figure figure, Point place)
{
  int heightF=figure.getHeight();
  int widhtF=figure.getWidth();
  int position = place.getX()+place.getY()*height;
  for (int line = 0; line < heightF; line++)
  {
    for (int col = 0; col < widhtF; col++)
    {
      image.at(line * width + col +position) = figure.getData(line *widhtF+ col);
    }
  }

}

// @brief draw is the function who draw all the figure in the vector of figure
// @param NULL
// @return NULL
void Drawing::draw()
{
  if (placeList.size()!=figList.size())
  {
    exit(0);
  }
  for(int a=0;a<placeList.size();a++)
  {
    drawAFigure(figList.at(a),placeList.at(a));
  }
}


//            _             _                      _    _           _
//  ___  _ _ <_> _ _  ___ _| |_ ___  ._ _ _  ___ _| |_ | |_  ___  _| | ___
// | . \| '_>| || | |<_> | | | / ._> | ' ' |/ ._> | |  | . |/ . \/ . |<_-<
// |  _/|_|  |_||__/ <___| |_| \___. |_|_|_|\___. |_|  |_|_|\___/\___|/__/
// |_|

/* Set every point of the image to 0 */
void Drawing::clearImage()
{
  for (std::vector<unsigned char>::iterator it = image.begin(); it != image.end();
       it++)
  {
    *it = 0;
  }
}

/* Set image to test */
void Drawing::createTestImage()
{
  for (int j = 0; j < height; j++)
  {
    for (int i = 0; i < width; i++)
    {
      image[j * width + i] = (i + j) % 256;
    }
  }
}

// @brief add a figure in the save's vector also his place 
// @param figure the param of the class Figure you want to add to the vector
// @param place the param of the class Point is the place you want to add to the vector
// @return if the add is good
bool Drawing::addStockage(Figure figure, Point place)
{
  if (place.getX() < width || place.getX() > 0)
  {
    if (place.getY() < width || place.getY() > 0)
    {
      placeList.push_back(place);
      figList.push_back(figure);
    }
  }
  //  printf("%ld",placeList.size());
  //  fflush(stdout);
}
