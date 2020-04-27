#include <iostream>
#include "Graphe.h"
#include "Svgfile.h"
#include <string>

void menu()
{
    std::cout << "------- MENU -------" << std::endl;
    std::cout << std::endl << "1. Charger un graphe\n"
              "2. Changer le systeme de ponderation d'un graphe\n"
              "3. Calculer l'indice de centralite\n"
              "4. Tester la vulnerabilite" << std::endl;

    std::cout << std::endl << "Choisissez une option !" << std::endl;

    int choix1;
    std::string choix2;

    std::cin >> choix1;

    while((choix1 > 4)|| (choix1 < 0))
    {
        std::cout << "Ne correspond pas a un choix possible\n"
                  "Veuillez ressaisir votre choix" << std::endl;

        std::cin >> choix1;
    }

    std::string nom,nom2;

    switch(choix1)
    {
    case 1:
        {
        std::cout << "Vous souhaitez charger un graphe\n"
                  "Veuillez choisir le nom du fichier (topologie) en .txt" << std::endl;
        std::cin >> nom;

        std::cout << "Voulez-vous ouvrir un fichier de ponderation (OUI/NON) ?\n";
        std::cin >> choix2;

        while((choix2 != "OUI")&&(choix2 != "NON"))
        {
            std::cout << "Ne correspond pas a un choix possible\n"
                      "Veuillez ressaisir votre choix" << std::endl;

            std::cin >> choix2;
        }

        if(choix2 == "OUI")
        {
            std::cout << "Vous souhaitez charger une ponderation\n"
                      "Veuillez choisir le nom du fichier (ponderation) en .txt" << std::endl;
            std::cin >> nom2;
        }
        else
            nom2 = "vide";

        Graphe g{nom,nom2};     //ouverture du fichier
        Svgfile svgout;
        g.afficher();
        g.afficherGrapheSvg(&svgout);
        }
        break;

    case 2:
        std::cout << "2_OK" << std::endl;
        break;

    case 3:
        std::cout << "3_OK" << std::endl;
        break;

    case 4:
        std::cout << "4_OK" << std::endl;
        break;
    }
}


int main()
{

    menu();

    return 0;
}
