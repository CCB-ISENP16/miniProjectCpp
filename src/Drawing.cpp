#include "Drawing.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>
#include <stdexcept>

//            _    _  _                     _    _           _
//  ___  _ _ | |_ | |<_> ___  ._ _ _  ___ _| |_ | |_  ___  _| | ___
// | . \| | || . \| || |/ | ' | ' ' |/ ._> | |  | . |/ . \/ . |<_-<
// |  _/`___||___/|_||_|\_|_. |_|_|_|\___. |_|  |_|_|\___/\___|/__/
// |_|

Drawing::Drawing(const int width, const int height)
    : width(width), height(height)
{
  image.resize(width * height);
}

Drawing::~Drawing() {}

/* Save image to file "filename" */
void Drawing::save(std::string filename)
{

  if (filename.substr(filename.find_last_of(".") + 1) != "bmp")
  {
    throw std::runtime_error(
        "Drawing ne supporte que l'enregistrement d'images au format bmp");
  }
#ifdef TEST
  createTestImage();
#endif
  stbi_write_bmp(filename.c_str(), width, height, 1, image.data());
}

void Drawing::draw(Figure figure, Point place)
{
  int heightF=figure.getHeight();
  int widhtF=figure.getWidth();
  for (int line = 0; line < heightF; line++)
  {
    for (int col = 0; col < widhtF; col++)
    {
      image.at(line * widhtF + col) = figure.getData(line * widhtF + col);
    }
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
  for (std::vector<char>::iterator it = image.begin(); it != image.end();
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
}
