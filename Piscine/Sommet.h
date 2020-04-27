#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED
#include <vector>
#include <fstream>

class Sommet
{
private:
    double m_id,m_x,m_y;
    char m_nom;
    std::vector<std::pair<const Sommet*,double>> m_successeurs;

public:

    Sommet(std::ifstream& is);

    ~Sommet();

    int getId() const
    {
        return m_id;
    }

    ///accesseur : pour la liste des successeurs
    const std::vector<std::pair<const Sommet*,double>>& getSuccesseurs() const;

    void ajouterSucc(std::pair<const Sommet*,double> voisin);

    void afficherVoisins() const;


    ///accesseur : pour la liste des successeurs
    const std::vector<const Sommet*>& getSuccesseurs() const;

    void ajouterSucc1(const Sommet* voisin);             //fonction d'ajout de successeur

};

#endif // SOMMET_H_INCLUDED
