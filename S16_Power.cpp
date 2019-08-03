// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。

#include<iostream>

using namespace std;
double EPSINON = 10e-9;
double powerWithUnsignedExponent(double base, unsigned int exponent)
{
    if (exponent == 0)
        return 1.0;
    if (exponent == 1)
        return base;
    double result = powerWithUnsignedExponent(base, exponent >> 1); //位运算效率高
    result *= result;
    if (exponent & 0x1 == 1)
        result *= base;
    return result;
}

// 常规方法
double powerWithUsignedExponent_2(double base, unsigned int exponent)
{
    int i = 0;
    double result = 1.0;
    while (i<exponent)
    {
        result *= base;
        ++i;
    }
    return result;
}

double Power(double base, int exponent)
{
    if ((base>=-EPSINON && base<=EPSINON) && exponent < 0)
        throw new std::exception();
    unsigned int absExponent = (unsigned int) exponent;
    if (exponent < 0)
        absExponent = (unsigned int)(-exponent);
    double result = powerWithUnsignedExponent(base, absExponent);
    if (exponent < 0)
        result = 1.0/result;
    return result;
}

int main()
{
    cout << "Power(10, 2): "<< Power(10, 2) << endl;
    cout << "Power(2.5, 3): "<< Power(2.5, 3) << endl;
    cout << "Power(2.5, -2): "<< Power(2.5, -2) << endl;
    cout << "Power(0, -2): "<< Power(0, -2) << endl;
    return 0;
}
