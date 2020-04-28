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
const std::vector<std::pair<const Sommet*,double>>& Sommet::getSuccesseurs() const
    {
        return m_successeurs;
    }

void Sommet::ajouterSucc(std::pair<const Sommet*,double> voisin)        //on ajoute un successeur
    {
        m_successeurs.push_back(voisin);
    }

void Sommet::afficherVoisins() const                                    //on affiche les voisins
    {
        std::cout << "sommet " << m_id << " : " ;
        for(const auto s : m_successeurs)
            std::cout << " " << s.first->getID();
    }


/*void Sommet::afficherSommetSvg(Svgfile* svgout) const
{
    svgout->addCross(m_x,m_y,0,"green");
    svgout->addText(m_x,m_y,m_nom,"red");
}*/

