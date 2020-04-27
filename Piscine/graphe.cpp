#include "Graphe.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

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
    ifs >> taille;                              //lecture de la taille(nombre d'ar�tes)
    if ( ifs.fail() )
        std::cout<<"pb de lecture taille\n";

    double num1,num2,idT,idP;
    std::string ligne;

    for (int i=0; i<taille; ++i)
    {
        ifs >> idT >> num1 >> num2;                          //lecture des ID des ar�tes

        if(nomFichierpond != "vide")                        //si ouverture d'une ponderation
        {
            std::ifstream ifs2{nomFichierpond};              //lecture du fichier
            if (!ifs2)
                std::cout << "pb d'ouverture ou nom du fichier ponderation\n";

            double taille2;
            ifs2 >> taille2;                              //lecture de la taille(nombre d'ar�tes)
            if ( ifs.fail() )
                std::cout << "pb de lecture taille\n";

            if(taille != taille2)
            {
                std::cout << "Probleme au niveau du nombre d'arete, pas la meme taille\n";
            }

            double poids;
            for (int i=0; i<taille; ++i)
            {
                ifs2 >> idP >> poids;                 //lecture des ID des ar�tes et du poids de chacune

                if(idT == idP)                      //si mm arete
                {
                    m_aretes.push_back( new Arete(idT,num1,num2,poids) );

                    m_sommets[num1]->ajouterSucc(std::make_pair(m_sommets[num2],poids));        //ajout d'un successeur avec son poids

                    ///si le graphe n'est pas orient�
                    ///si num2 est successeur de num1, num1 est successeur de num2
                    if(!m_orient)
                        m_sommets[num2]->ajouterSucc(std::make_pair(m_sommets[num1],poids));
                }
            }
        }
        else
        {
            double poids = 0;

            m_aretes.push_back( new Arete(idT,num1,num2,poids) );

                    m_sommets[num1]->ajouterSucc(std::make_pair(m_sommets[num2],poids));        //ajout d'un successeur avec son poids

                    ///si le graphe n'est pas orient�
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
        s->afficherVoisins();                   //appelle du sspg pour afficher les successeurs � un sommet
        std::cout << std::endl;
    }
}

std::vector<int> Graphe::rechercheDijkstra(double num_F)   //algorithme de DIJKSTRA
    {

        auto cmp = [](std::pair<const Sommet*,double> p1, std::pair<const Sommet*,double> p2)
        {
            return p2.second<p1.second;
        };

        /// d�claration de la file de priorit�
        std::priority_queue<std::pair<const Sommet*,double>,std::vector<std::pair<const Sommet*,double>>,decltype(cmp)> file(cmp);

        /// pour le marquage
        std::vector<int> couleurs((int)m_sommets.size(),0);

        ///pour noter les pr�d�cesseurs : on note les num�ros des pr�d�cesseurs (on pourrait stocker des pointeurs sur ...)
        std::vector<int> preds((int)m_sommets.size(),-1);

        ///pour la distance
        std::vector<int> poids((int)m_sommets.size(),-1);


        ///initialisation
        poids[num_F]=0;
        file.push({m_sommets[num_F],0});

        std::pair<const Sommet*,double> p;

        while(!file.empty())
        {
            ///on marque le sommet s avec le plus petit poids
            p = file.top();
            file.pop();

            ///pour chaque successeur du sommet d�fil�
            while((!file.empty())&&(couleurs[p.first->getID()] ==1))
            {
                p=file.top();
                file.pop();
            }
            couleurs[p.first->getID()]=1;          //on marque le sommet

            for(auto succ : p.first->getSuccesseurs())          //pour chaque successeur
            {
                if(couleurs[succ.first->getID()] == 0) ///si non marqu�
                {
                    if( (poids[p.first->getID()] + succ.second < poids[succ.first->getID()]) || (poids[succ.first->getID()] == -1) ) ///si distance inf�rieur
                    {
                        poids[succ.first->getID()] = poids[p.first->getID()] + succ.second;       //on met � jour les distances
                        preds[succ.first->getID()] = p.first->getID();                            //on note le pr�decesseur
                        file.push({succ.first,poids[succ.first->getID()]});                        //on ajoute la pair dans la file
                    }
                }
            }
        }
        return preds;
    }


/*
sous-programme qui affiche une arborescence
params : sommet initial (racine), vecteur de pr�d�cesseur
*/

void Graphe::afficher_parcours(double num1, double num2, const std::vector<int>& arbre)
{

            if(arbre[num2]!=-1)
            {
                std::cout<<num2<<" <-- ";
                size_t j=arbre[num2];

                while(j!=num1)
                {
                        std::cout<<j<<" <-- ";
                        j=arbre[j];
                }
                std::cout<<j<<std::endl;

                size_t a=num2;
                int somme=0;

                while(a!=num1)
                {
                        for(auto succ: m_sommets[arbre[a]]->getSuccesseurs())
                            {
                                if(succ.first->getID()==a)
                                {
                                        std::cout << succ.second << " + ";
                                        somme = somme + succ.second;
                                }
                            }
                            a=arbre[a];
                }
                std::cout << "somme : " << somme;
            }
}
/*
void Graphe::afficherGrapheSvg(Svgfile* svgout) const
{
    for(size_t i=0; i<m_sommets.size(); ++i)
    {
        m_sommets[i]->afficherSommetSvg(svgout);
    }

    for(size_t i=0; i<m_aretes.size(); ++i)
    {
        m_aretes[i]->afficherAreteSvg(svgout);
    }
    }*/
