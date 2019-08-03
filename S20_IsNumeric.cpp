// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是

#include<iostream>

using namespace std;
bool scanUnsignedInt(char** str)
{
    char* start = *str;
    while (**str != '\0' && **str >= '0' && **str <= '9')
        ++(*str);
    return *str > start; // 有整数存在
}

bool scanInt(char** str)
{
    if (**str == '+' || **str == '-')
        ++(*str);
    return scanUnsignedInt(str);
}

bool isNumeric(char* str)
{
    bool numeric = scanInt(&str);  //扫描整数部分
    if (*str == '.') // 小数部分
    {
        ++str;
        numeric = scanUnsignedInt(&str) || numeric; // numeric放在后面。。。
    }
    if (*str == 'e' || *str == 'E')
    {
        ++str;
        numeric = numeric && scanInt(&str);
    }
    return numeric && (*str == '\0');
}

int main()
{
    char str[] = "-123.456E-11";
    char* pt = str;
    cout << isNumeric(pt) << endl;
    return 0;
}