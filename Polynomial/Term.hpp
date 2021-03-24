#pragma once
#include "Monomial.hpp"

class Term
{
private:
    double coeff;
    Monomial mono;

public:
    Term()
    {
        coeff = 1;
    }
    Term(double m_coeff, const Monomial &m_mono) : coeff(m_coeff), mono(m_mono)
    {
    }
    
};