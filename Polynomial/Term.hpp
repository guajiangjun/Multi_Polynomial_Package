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
    friend ostream &operator<<(ostream &out, Term &t)
    {
        out << "函数项:\t系数\t次数" << endl;
        out << "    \t" << t.coeff << "\t" << t.mono << endl;
        return out;
    }
};