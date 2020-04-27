#include "Arete.h"
#include <fstream>
#include <iostream>

Arete::Arete(double& id, double& num1, double& num2, double& poids)
{
        m_id = id;
        m_num1 = num1;
        m_num2 = num2;
        m_poids = poids;
}

Arete::~Arete()
{}

void Arete::afficherAreteSvg(Svgfile* svgout) const
{
    for(size_t i=0; i<)

    svgout->addLine();
}
