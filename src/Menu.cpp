#include "Menu.h"
#include "Drawing.h"
#include "FigSquare.h"
#include "FigCross.h"
#include "FigRect.h"
#include "Point.h"
#include "string.h"
#include "FigTriangle.h"
#include "FigArrow.h"
#include <string>

// @brief this function run is the active menu call for start the appliaction
// you can choose with number between 1 to 8 for start a action
// @param NULL
// @return NULL
void Menu::run()
{
    char FicNamePreview[] = "preview";

    std::cout << "width :" << std::endl;
    std::cin >> width;
    std::cout << "height :" << std::endl;
    std::cin >> height;
    // created of the drawing space , this define in Drawing.cpp
    Drawing draw(width, height);

    while (1)
    {
        std::cout << "Que voulez vous faire ?\n1) Carré\n2) Croix\n3) Rectangle\n4) Triangle\n5) Fleche\n6) Save\n7) Open Preview (beta for next holydays)\n8) Quit"
                  << std::endl;
        std::cin >> choose;
        switch (choose)
        {

        case 1:
        {
            //for square and cross we use pointer because during the deallocate of memory we have a double free in this area of region
            // std::cout << "choisissez la cote du carré, sa position en X et en Y" << std::endl;
            std::cout << "Creation d'un carre !" << std::endl;
            std::cout << "width :" << std::endl;
            std::cin >> widthf;
            std::cout << "X :" << std::endl;
            std::cin >> X;
            std::cout << "Y :" << std::endl;
            std::cin >> Y;

            std::cout << "Thinkness :" << std::endl;
            std::cin >> Thinkness;

            Point place0(X, Y);
            Carre *square = new Carre(widthf,Thinkness);
            draw.addStockage(*square, place0);
            place0.~Point();
            delete (square);
            system("clear");
            break;
        }
        case 2:
        {
            std::cout << "Creation d'une croix !" << std::endl;
            std::cout << "width :" << std::endl;
            std::cin >> widthf;
            std::cout << "height :" << std::endl;
            std::cin >> heightf;

            std::cout << "X :" << std::endl;
            std::cin >> X;
            std::cout << "Y :" << std::endl;
            std::cin >> Y;

            std::cout << "Thinkness :" << std::endl;
            std::cin >> Thinkness;

            Cross *cross = new Cross(widthf, heightf,Thinkness);
            Point place1(X, Y);
            draw.addStockage(*cross, place1);
            place1.~Point();
            delete (cross);
            system("clear");
            break;
        }
        case 3:
        {
            std::cout << "Creation d'un rectangle !" << std::endl;
            std::cout << "width :" << std::endl;
            std::cin >> widthf;
            std::cout << "height :" << std::endl;
            std::cin >> heightf;

            std::cout << "X :" << std::endl;
            std::cin >> X;
            std::cout << "Y :" << std::endl;
            std::cin >> Y;

            std::cout << "Thinkness :" << std::endl;
            std::cin >> Thinkness;

            Rect rect(widthf, heightf,Thinkness);
            Point place2(X, Y);
            draw.addStockage(rect, place2);
            rect.~Rect();
            place2.~Point();
            system("clear");
            break;
        }

        case 4:
        {
            std::cout << "Creation d'un triangle !" << std::endl;
            std::cout << "width :" << std::endl;
            std::cin >> widthf;
            std::cout << "height :" << std::endl;
            std::cin >> heightf;

            std::cout << "X :" << std::endl;
            std::cin >> X;
            std::cout << "Y :" << std::endl;
            std::cin >> Y;

            std::cout << "Thinkness :" << std::endl;
            std::cin >> Thinkness;

            Triangle triangle(widthf, heightf,Thinkness);
            Point place1(X, Y);
            draw.addStockage(triangle, place1);
            place1.~Point();
            triangle.~Triangle();
            system("clear");
            break;
        }

        case 5:
        {
            std::cout << "Creation d'une fleche !" << std::endl;
            std::cout << "width :" << std::endl;
            std::cin >> widthf;
            std::cout << "height :" << std::endl;
            std::cin >> heightf;

            std::cout << "X :" << std::endl;
            std::cin >> X;
            std::cout << "Y :" << std::endl;
            std::cin >> Y;

            std::cout << "Thinkness :" << std::endl;
            std::cin >> Thinkness;

            Arrow arrow(widthf, heightf, Thinkness);
            Point place1(X, Y);
            draw.addStockage(arrow, place1);
            place1.~Point();
            arrow.~Arrow();
            system("clear");
            break;
        }

        case 6:
        {
            // int list;
            // scanf("%d",&list);
            // draw.drawInTerminal(list);
            save();
            draw.save(FicName);
            break;
        }
        case 8:
        {
            quit();
            draw.save(FicName);
            draw.~Drawing();
            exit(0);
            break;
        }

            // case 7:
            // {
            //     std::cout<< "before using it install: xwiever "<< std::endl;
            //     snprintf(FicNamePreview + strlen(FicNamePreview), 5, "%s", ".bmp");
            //     draw.save(FicNamePreview);
            //     try{
            //        if( !system("eog preview.bmp"))
            //             throw  string::string("on ne peut pas ouvrir l'application");
            //     }

            //     system("rm -rf preview.bmp");
            //     system("clear");
            //     break;
            // }

        default:
        {
            break;
        }
        }
    }
}
// @brief save is the function for save your work with the creation and placement of of your Figure
// @param NULL
// @return NULL
void Menu::save()
{
    std::cout << "Vous allez enregistrer, taper le nom du fichier: (50 caractere max )" << std::endl;
    std::cin >> FicName;
    snprintf(FicName + strlen(FicName), 5, "%s", ".bmp");
}

// @brief quit is the function for quit the application and you save your work with the creation and placement of of your Figure
// @param NULL
// @return NULL
void Menu::quit()
{
    std::cout << "Vous allez quitter, taper le nom du fichier: (50 caractere max ) pour sauvegarder" << std::endl;
    std::cin >> FicName;
    snprintf(FicName + strlen(FicName), 5, "%s", ".bmp");
}

// @brief this the constructor for the classe Menu
// @param NULL
// @return NULL
Menu::Menu()
{
    std::cout << "bienvenue dans votre application Paint " << std::endl;
};
Menu::~Menu(){};