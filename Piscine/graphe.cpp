#include "Graphe.h"
#include <iostream>
#include <fstream>
#include <vector>


Graphe::Graphe(std::string nomFichiertopo,std::string nomFichierpond)              //constructeur
{
    std::ifstream ifs{nomFichiertopo};              //lecture du fichier
    if (!ifs)
        std::cout<<"pb d'ouverture ou nom du fichier\n";

    if(nomFichierpond == "vide")
    {
        ifs >> m_orient;                            //lecture de l'orientation
        if ( ifs.fail() )
            std::cout << "pb de lecture orientation\n";

        double ordre;
        ifs >> ordre;                               //lecture ordre
        if ( ifs.fail() )
            std::cout << "pb de lecture ordre\n";

        for(int i=0; i<ordre; ++i)
        {
            m_sommets.push_back( new Sommet{ifs} );
        }

        double taille;
        ifs >> taille;                              //lecture de la taille(nombre d'arêtes)
        if ( ifs.fail() )
            std::cout<<"pb de lecture taille\n";

        double id,num1,num2;

        for (int i=0; i<taille; ++i)
        {
            m_aretes.push_back( new Arete(ifs) );

            ifs >> num1 >> num2;                //lecture des ID des arêtes
            m_sommets[num1]->ajouterSucc1(m_sommets[num2]);      //création du successeur de sommet

            ///si le graphe n'est pas orienté
            ///si num2 est successeur de num1, num1 est successeur de num2
            if(!m_orient)
                m_sommets[num2]->ajouterSucc1(m_sommets[num1]);
        }
    }

    else
    {
        std::ifstream ifs2{nomFichiertopo};              //lecture du fichier
        if (!ifs2)
            std::cout << "pb d'ouverture ou nom du fichier\n";

        double taille;
        ifs2 >> taille;                              //lecture de la taille(nombre d'arêtes)
        if ( ifs.fail() )
            std::cout << "pb de lecture taille\n";

        double poids;
        for (int i=0; i<taille; ++i)
        {
            ifs2 >> num1 >> num2 >> poids;                 //lecture des ID des arêtes et du poids de chacune
            m_sommets[num1]->ajouterSucc(std::make_pair(m_sommets[num2],poids));        //ajout d'un successeur avec son poids


            ///si le graphe n'est pas orienté
            ///si num2 est successeur de num1, num1 est successeur de num2
            if(!m_orient)
                m_sommets[num2]->ajouterSucc(std::make_pair(m_sommets[num1],poids));
        }

    }
}

Graphe::~Graphe()       //destructeur
{
    for (auto s : m_sommets)
        delete s;
}

void Graphe::menu() const
{
    std::cout << "------- MENU -------" << std::endl;
    std::cout << std::endl << "1. Charger un graphe\n"
              "2. Changer le systeme de ponderation d'un graphe\n"
              "3. Calculer l'indice de centralite\n"
              "4. Tester la vulnerabilite" << std::endl;

    std::cout << std::endl << "Choisissez une option !" << std::endl;
    int choix1,choix2;
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
        std::cout << "Vous souhaitez charger un graphe\n"
                  "Veuillez choisir le nom du fichier (topologie) en .txt" << std::endl;
        std::cin >> nom;

        std::cout << "Voulez-vous ouvrir un fichier de ponderation (OUI/NON) ?\n";
        std::cin >> choix2;

        while((choix2 =! "OUI")&&(choix2 =! "NON"))
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

void Graphe::afficher() const           //fonction d'affichage du graphe
{
    if(m_orient == 0)
        std::cout << "Graphe non oriente\n";
    else
        std::cout << "Graphe oriente\n";

    std::cout << "Ordre : " << m_sommets.size() << std::endl;
    std::cout << "Liste successeurs graphe" << std::endl;

    for(const auto s : m_sommets)       //appelle de l'affichage des successeurs
    {
        s->afficherVoisins();
        std::cout << std::endl;
    }
}
