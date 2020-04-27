#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include <fstream>
#include "svgfile.h"

class Arete
{
private:
    double m_id, m_num1, m_num2, m_poids;

public:
    Arete(double& id, double& num1, double& num2, double& poids);

    ~Arete();

    void afficherAreteSvg(Svgfile* svgout) const;
};

#endif // ARETE_H_INCLUDED
