#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED
#include <fstream>

class Arete
{
private:
    double m_id, m_num1, m_num2, m_poids;

public:
    Arete(std::ifstream& iss);

    ~Arete();
};

#endif // ARETE_H_INCLUDED
