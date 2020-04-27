#include "Arete.h"
#include <fstream>
#include <iostream>

Arete::Arete(std::ifstream& iss)
{
        iss >> m_id >> m_num1 >> m_num2;
        if ( iss.fail() )
                std::cout << "Probleme lecture arete\n";
}

Arete::~Arete()
{}
