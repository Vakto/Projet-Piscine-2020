#include "Sommet.h"
#include <vector>
#include <iostream>
#include <fstream>

Sommet::Sommet(std::ifstream& is)
    {
        is >> m_id >> m_nom >> m_x >> m_y;
        if ( is.fail() )
                std::cout << "Probleme lecture sommet\n";

    }

Sommet::~Sommet()               //destructeur
    {}

    ///accesseur : pour la liste des successeurs
    const std::vector<const Sommet*>& Sommet::getSuccesseurs() const
    {
        return m_successeurs;
    }

    void Sommet::ajouterSucc(const Sommet* voisin)          //on ajoute un sucesseur
    {
        m_successeurs.push_back(voisin);
    }

    void Sommet::afficherVoisins()                          //on affiche les succeseurs
    {
        std::cout << "sommet " << m_id << " : " ;
        for(const auto s : m_successeurs)
            std::cout << " " << s->m_id;
    }
