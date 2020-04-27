#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include <vector>
#include "Sommet.h"
#include "Arete.h"
#include "svgfile.h"


class Graphe
{
private:
    std::vector<Sommet*> m_sommets;
    std::vector<Arete*> m_aretes;
    int m_orient;

public:
    Graphe(std::string nomFichiertopo,std::string nomFichierpond);

    ~Graphe();

    void afficher() const;
    void afficherGrapheSvg(Svgfile* svgout) const;

     //proximit�

    std::vector <int> rechercheDijkstra (double num_F);
    void afficher_parcours(double num1, double num2, const std::vector<int>& arbre);
};


#endif // GRAPHE_H_INCLUDED
