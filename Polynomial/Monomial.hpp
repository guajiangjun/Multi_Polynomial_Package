#pragma once
#include "../Geometry/Point.hpp"
class Monomial
{
private:
    vector<int> degree;

public:
    //无参构造函数
    Monomial()
    {
        degree.push_back(0);
    }
    //有参构造函数
    Monomial(vector<int> m_degree) : degree(m_degree)
    {
    }
    int getLength()
    {
        return degree.size();
    }
    int &operator[](int i)
    {
        return degree[i];
    }
    double operator()(Point &p)
    {
        double result = 1;
        for (int i = 0; i < degree.size(); i++)
        {
            result *= pow(p[i], degree[i]);
        }
        return result;
    }
    double operator()(vector<double> &p)
    {
        double result = 1;
        for (int i = 0; i < degree.size(); i++)
        {
            result *= pow(p[i], degree[i]);
        }
        return result;
    }
    //重载输出运算符<<
    friend ostream &operator<<(ostream &out, Monomial &m)
    {
        out << "(" << m[0];
        for (int i = 1; i < m.getLength(); i++)
        {
            out << "," << m[i];
        }
        out << ")";
        return out;
    }
};
