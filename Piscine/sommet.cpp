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

Sommet::~Sommet()
    {}

///accesseur : pour la liste des successeurs
    const std::vector<const Sommet*>& Sommet::getSuccesseurs() const
    {
        return m_successeurs;
    }

    void Sommet::ajouterSucc1(const Sommet* voisin)          //on ajoute un sucesseur
    {
        m_successeurs.push_back(voisin);
    }

///accesseur : pour la liste des successeurs
const std::vector<std::pair<const Sommet*,double>>& Sommet::getSuccesseurs() const
    {
        return m_successeurs;
    }

void Sommet::ajouterSucc(std::pair<const Sommet*,double> voisin)
    {
        m_successeurs.push_back(voisin);
    }

