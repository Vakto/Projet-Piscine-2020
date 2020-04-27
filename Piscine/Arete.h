#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include <fstream>
#include "svgfile.h"

class Arete
{
private:
    double m_id, m_poids;
    int m_num1, m_num2;

public:
    Arete(double& id, int& num1, int& num2, double& poids);

    ~Arete();

    int get_Num1() const
    {
        return m_num1;
    }

    int get_Num2() const
    {
        return m_num2;
    }
};

#endif // ARETE_H_INCLUDED
