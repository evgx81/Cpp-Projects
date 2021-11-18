#include "hyperbola.hh"

#include <cmath>

double Hyperbola::calculateFunction()
{
    if(abs(m_x) < m_a)
        throw std::invalid_argument("Значение x выходит за пределы действительной полуоси!");

    return (m_b / m_a) * sqrt(m_x * m_x - m_a * m_a);
}

int Hyperbola::analyzeData()
{
    int countSolutions{};
    if (calculateFunction() == 0)
        countSolutions = 1;
    if (calculateFunction() != 0) 
        countSolutions = 2;
    return countSolutions;   
}

void Hyperbola::setX(double x)
{
    m_x = x;
}

std::string Hyperbola::showData()
{
    std::string y{};
    y += "Значения y в уравнении ";
    y += "x^2/" + std::to_string(pow(m_a, 2)) + " + y^2/" + std::to_string(pow(m_b, 2)) + "= 1\n";
    y += "равны ";

    int solutions = analyzeData();
    
    if (solutions == 1)
    {
        y +=  "y = " + std::to_string(calculateFunction()) + '\n';
    }
    else if (solutions == 2)
    {
        y += "y1 = " + std::to_string(calculateFunction()) + '\n';
        y += "y2 = -" + std::to_string(calculateFunction()) + '\n';;
    }
    else
        y += "Корней не существует!\n";

    return y;

}
