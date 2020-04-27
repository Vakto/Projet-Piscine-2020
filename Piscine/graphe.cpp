#include "Graphe.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

Graphe::Graphe(std::string nomFichiertopo,std::string nomFichierpond)              //constructeur
{
    std::ifstream ifs{nomFichiertopo};              //lecture du fichier
    if (!ifs)
        std::cout<<"pb d'ouverture ou nom du fichier\n";



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

        double num1,num2,id;
        std::string ligne;

        for (int i=0; i<taille; ++i)
        {
            ifs >> id >> num1 >> num2;                          //lecture des ID des arêtes

            m_aretes.push_back( new Arete(id,num1,num2) );

            m_sommets[num1]->ajouterSucc(m_sommets[num2]);      //création du successeur de sommet

            ///si le graphe n'est pas orienté
            ///si num2 est successeur de num1, num1 est successeur de num2
            if(!m_orient)
                m_sommets[num2]->ajouterSucc(m_sommets[num1]);
        }

    if(nomFichierpond != "vide")
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
            ifs2 >> id >> poids;                 //lecture des ID des arêtes et du poids de chacune
        }
    }
}

Graphe::~Graphe()       //destructeur
{
    for (auto s : m_sommets)
        delete s;
}

void Graphe::afficher() const                   //fonction d'affichage du fichier
    {
        if(m_orient == 0)
            std::cout << "Graphe non oriente\n";
        else
            std::cout << "Graphe oriente\n";


        std::cout << "Ordre : " << m_sommets.size() << std::endl;
        std::cout << "Liste sommets " << std::endl;

        for(const auto s : m_sommets)
        {
            s->afficherVoisins();                   //appelle du sspg pour afficher les successeurs à un sommet
            std::cout << std::endl;
        }
    }
