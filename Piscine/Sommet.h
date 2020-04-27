#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <vector>
#include <fstream>

class Sommet
{
private:
    double m_id,m_x,m_y;
    char m_nom;
    std::vector<const Sommet*> m_successeurs;           //vecteur de successeurs


public:

    Sommet(std::ifstream& is);

    ~Sommet();

    ///accesseur : pour la liste des successeurs
    const std::vector<const Sommet*>& getSuccesseurs() const;

    void ajouterSucc(const Sommet* voisin);             //fonction d'ajout de successeur

    void afficherVoisins();                             //fonction d'affichage de successeurs

};

#endif // SOMMET_H_INCLUDED
