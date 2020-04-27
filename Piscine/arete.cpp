#include "Arete.h"
#include <fstream>
#include <iostream>

Arete::Arete(double& id, double& num1, double& num2)
{
        m_id = id;
        m_num1 = num1;
        m_num2 = num2;

        std::cout << m_id << m_num1 << m_num2 << std::endl;
}

Arete::~Arete()
{}
