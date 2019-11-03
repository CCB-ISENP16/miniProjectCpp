#include "Menu.h"
#include "Drawing.h"
#include "FigSquare.h"
#include "FigCross.h"
#include "FigRect.h"
#include "Point.h"
#include "string.h"
#include "FigTriangle.h"

void Menu::run()
{
    std::cout << "width :" << std::endl;
    std::cin >> width;
    std::cout << "height :" << std::endl;
    std::cin >> height;

    Drawing draw(width, height);

    std::cout << "H : " << height << "\nW :" << width << std::endl;

    while (1)
    {
        std::cout << "Que voulez vous faire ?\n1) Carré\n2) Croix\n3) Rectangle\n4) Triangle\n5) Save\n6) Quit"
                  << std::endl;
        std::cin >> choose;
        switch (choose)
        {

        case 1:
        {
            // std::cout << "choisissez la cote du carré, sa position en X et en Y" << std::endl;
            std::cout << "Creation d'un carre !"<<std::endl;
            std::cout << "width :" << std::endl;
            std::cin >> widthf;
            std::cout << "X :" << std::endl;
            std::cin >> X;
            std::cout << "Y :" << std::endl;
            std::cin >> Y;

            Point place0(X, Y);
            Carre square(widthf);
            draw.addStockage(square, place0);
            place0.~Point();
            square.~Carre();
            break;
        }
        case 2:
        {
            std::cout << "Creation d'une croix !"<<std::endl;
            std::cout << "width :" << std::endl;
            std::cin >> widthf;
            std::cout << "height :" << std::endl;
            std::cin >> heightf;

            std::cout << "X :" << std::endl;
            std::cin >> X;
            std::cout << "Y :" << std::endl;
            std::cin >> Y;

            Cross cross(widthf, heightf);
            Point place1(X, Y);
            draw.addStockage(cross, place1);
            place1.~Point();
            cross.~Cross();
            break;
        }
        case 3:
        {
            std::cout << "Creation d'un rectangle !"<<std::endl;
            std::cout << "width :" << std::endl;
            std::cin >> widthf;
            std::cout << "height :" << std::endl;
            std::cin >> heightf;

            std::cout << "X :" << std::endl;
            std::cin >> X;
            std::cout << "Y :" << std::endl;
            std::cin >> Y;

            Rect rect(widthf, heightf);
            Point place2(X, Y);
            draw.addStockage(rect, place2);
            rect.~Rect();
            place2.~Point();
            break;
        }

        case 4:
        {
            std::cout << "Creation d'un triangle !"<<std::endl;
            std::cout << "width :" << std::endl;
            std::cin >> widthf;
            std::cout << "height :" << std::endl;
            std::cin >> heightf;

            std::cout << "X :" << std::endl;
            std::cin >> X;
            std::cout << "Y :" << std::endl;
            std::cin >> Y;

            Triangle triangle(widthf, heightf);
            Point place1(X, Y);
            draw.addStockage(triangle, place1);
            place1.~Point();
            triangle.~Triangle();
            // cross.~Cross();
            break;
        }

        case 5:
        {
            save();
            draw.save(FicName);
            break;
        }
        case 6:
        {
            quit();
            draw.save(FicName);
            exit(0);
            break;
        }
        default:
        {
            break;
        }
        }
    }
}

void Menu::save()
{
    std::cout << "Vous allez enregistrer, taper le nom du fichier: (50 caractere max )" << std::endl;
    std::cin >> FicName;
    snprintf(FicName + strlen(FicName), 5, "%s", ".bmp");
}

void Menu::quit()
{
    std::cout << "Vous allez quitter, taper le nom du fichier: (50 caractere max ) pour sauvegarder" << std::endl;
    std::cin >> FicName;
    snprintf(FicName + strlen(FicName), 5, "%s", ".bmp");
}

Menu::Menu()
{
    std::cout << "bienvenue dans votre application Paint " << std::endl;
};
Menu::~Menu(){};