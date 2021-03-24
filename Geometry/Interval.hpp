#pragma once
#include "../includeSTL.hpp"
class Interval
{
private:
    double a, b;

public:
#pragma region 构造函数和输出函数
    //构造函数
    Interval(double m_a = 0, double m_b = 0) : a(m_a), b(m_b)
    {
        if (a > b)
        {
            throw invalid_argument("Interval() Wong:a must be less than b!");
        }
    }
    //输出函数
    friend ostream &operator<<(ostream &out, const Interval &I)
    {
        return out << "(" << I.a << " , " << I.b << ")";
    }
#pragma endregion

#pragma region 区间基本处理
    //判断一个数是否所在区间之中
    friend bool ifIn(double d, const Interval &I)
    {
        return I.a < d && d < I.b;
    }

    //返回区间的长度
    double getLength() const { return b - a; }
    //返回区间的左端点和右端点（可以修改）
    double &operator[](int i)
    {
        if (i == 0)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    //返回区间的左端点和右端点（不可以修改）
    double operator()(int i) const
    {
        if (i == 0)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
#pragma endregion

#pragma region 区间算术

#pragma region +=
    //加等一个区间
    Interval &operator+=(const Interval &I)
    {
        a += I.a;
        b += I.b;
        return *this;
    }
    //加等一个常数
    Interval &operator+=(const double rhs)
    {
        a += rhs;
        b += rhs;
        return *this;
    }
#pragma endregion

#pragma region -=
    //减等一个区间
    Interval &operator-=(const Interval &I)
    {
        a -= I.b;
        b -= I.a;
        return *this;
    }
    //减等一个常数
    Interval &operator-=(const double rhs)
    {
        a -= rhs;
        b -= rhs;
        return *this;
    }

#pragma endregion

#pragma region *=

    //乘等一个区间
    Interval &operator*=(const Interval &I)
    {
        double n1 = a * I.a;
        double n2 = a * I.b;
        double n3 = b * I.a;
        double n4 = b * I.b;
        a = min(n1, min(n2, min(n3, n4)));
        b = max(n1, max(n2, max(n3, n4)));
        return *this;
    }
    //乘等一个常数
    Interval &operator*=(const double rhs)
    {
        double n1 = a * rhs;
        double n2 = b * rhs;
        a = min(n1, n2);
        b = max(n1, n2);
        return *this;
    }

#pragma endregion

#pragma endregion
};

#pragma region 区间取正和负
Interval operator+(const Interval &I)
{
    Interval re = I;
    return re;
}
Interval operator-(const Interval &I)
{
    Interval re;
    re[0] = -I(1);
    re[1] = -I(0);

    return re;
}
#pragma endregion

#pragma region 区间算术

#pragma region +
//两个区间相加
Interval operator+(const Interval &I, const Interval &J)
{
    Interval re = I;
    re += J;
    return re;
}
//一个区间和一个常数相加
Interval operator+(const Interval &I, double a)
{
    Interval re = I;
    re += a;
    return re;
}
//一个常数和一个区间相加
Interval operator+(double a, const Interval &J)
{
    Interval re = J;
    re += a;
    return re;
}
#pragma endregion

#pragma region -
//两个区间相减
Interval operator-(const Interval &I, const Interval &J)
{
    Interval re = I;
    re -= J;
    return re;
}
//一个区间减去一个常数
Interval operator-(const Interval &I, double a)
{
    Interval re = I;
    re -= a;
    return re;
}
//一个常数减去一个区间
Interval operator-(double a, const Interval &J)
{
    Interval re = -J;
    re += a;
    return re;
}
#pragma endregion

#pragma region *
//两个区间相乘
Interval operator*(const Interval &I, const Interval &J)
{
    Interval re = I;
    re *= J;
    return re;
}
//一个区间乘上一个常数
Interval operator*(const Interval &I, double a)
{
    Interval re = I;
    re *= a;
    return re;
}
//一个常数乘上一个区间
Interval operator*(double a, const Interval &J)
{
    Interval re = J;
    re *= a;
    return re;
}
#pragma endregion

#pragma endregion

#pragma region 区间相等判断
bool operator==(const Interval &I, const Interval &J)
{
    return I(0) == J(0) && I(1) == J(1);
}
bool operator!=(const Interval &I, const Interval &J)
{
    return ~(I == J);
}
#pragma endregion

Interval reverse(const Interval &I)
{
    double a = I(0);
    double b = I(1);
    double delta = 1e-100;
    if (a == 0)
    {
        a += delta;
    }
    if (b == 0)
    {
        b -= delta;
    }
    if (b < 0)
    {
        return Interval(1 / b, 1 / a);
    }
    else
    {
        return Interval(1 / b, 1 / a);
    }
}