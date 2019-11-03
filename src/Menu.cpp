#include "Menu.h"
#include "Drawing.h"
#include "FigSquare.h"
#include "FigCross.h"
#include "FigRect.h"
#include "Point.h"
#include "string.h"

void Menu::run()
{
    std::cout << "choisissez vos dimensions " << std::endl;
    std::cin >> width, height;
    Drawing draw(width, height);
    while (1)
    {
        std::cout << "Que voulez vous faire ?" << std::endl;
        std::cin >> choose;
        switch (choose)
        {
        case 1:
            std::cout << "ajouter une figure choisisez la! square [0] , cross [1], rectangle [2] " << std::endl;
            std::cin >> figure;
            std::cout << std::endl;

            switch (figure)
            {
                case 0:
                    std::cout << "choisissez la cote du carré, sa position en X et en Y" << std::endl;
                    std::cin >> widthf, X, Y;
                    Point place0(X, Y);
                    Carre square(widthf);
                    draw.addStockage(square, place0);
                    place0.~Point();
                    square.~Carre();
                    break;
                
                case 1:
                    std::cout << "choisissez les longueurs de la croix, largeur puis longueur, sa position en X et en Y" << std::endl;
                    std::cin >> widthf, heightf, X, Y;
                    Cross cross(widthf, heightf);
                    Point place1(X, Y);
                    draw.addStockage(cross, place1);
                    place1.~Point();
                    cross.~Cross();
                    break;

                case 2:
                    std::cout << "choisissez les longueurs du rectangle, largeur puis longueur, sa position en X et en Y" << std::endl;
                    std::cin >> widthf, heightf, X, Y;
                    Rect rect(widthf, heightf);
                    Point place2(X, Y);
                    draw.addStockage(rect, place2);
                    rect.~Rect();
                    place2.~Point();
                    break;

                default:
                    break;
            }
            break;

        case 2:
            void save();
            draw.save(FicName);
            break;

        case 3:
            quit();
            draw.save(FicName);
            exit(0);
            break;

        default:
            break;
        }
    }
}

void Menu::save()
{
    std::cout << "Vous allez enregistrer, taper le nom du fichier: (50 caractere max )" << std::endl;
    std::cin >> FicName;
    snprintf(FicName +strlen(FicName), 5, "%s", ".bmp");
}

void Menu::quit()
{
    std::cout << "Vous allez quitter, taper le nom du fichier: (50 caractere max ) pour sauvegarder" << std::endl;
    std::cin >> FicName;
    snprintf(FicName + strlen(FicName), 5, "%s", ".bmp");
}

Menu::Menu ()
{
    std::cout << "bienvenue dans votre application Paint " << std::endl;
};
Menu::~Menu (){};