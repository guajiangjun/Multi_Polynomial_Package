#pragma once
#include "../includeSTL.hpp"
class Point
{
private:
    vector<double> p;

public:
    Point()
    {
        p.push_back(0);
    }
    Point(const vector<double> &m_p) : p(m_p)
    {
    }
    int getLength()
    {
        return p.size();
    }
    double &operator[](int i)
    {
        return p[i];
    }
    friend ostream &operator<<(ostream &out, Point &p)
    {
        out << "点的坐标为: (" << p[0];
        for (int i = 1; i < p.getLength(); i++)
        {
            out << "," << p[i];
        }
        out << ")";
        return out;
    }
};