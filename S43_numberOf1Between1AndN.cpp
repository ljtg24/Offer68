// #include <bits/stdc++.h>
#include <iostream>
// #include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int powerBase10(unsigned int n)
{
    int result = 1;
    for (unsigned int i = 0; i < n; ++i)
        result *= 10;
    return result;
}

int numberOf1(const char* strN)
{
    if (strN == nullptr || *strN < '0' || *strN > '9' || *strN == '\0')
        return 0;
    int first = *strN - '0';
    unsigned int length = static_cast<unsigned int>(strlen(strN));
    if (length == 1 && first == 0)
        return 0;
    if (length == 1 && first > 0)
        return 1;
    int numFirstDigit = 0;  // 最高位1出现的次数
    if (first > 1)
        numFirstDigit = powerBase10(length-1);
    else if (first == 1)
        numFirstDigit = atoi(strN+1) + 1;
    
    int numOthers = 0;  // 除最高位其他位出现1 的次数
    numOthers = first * (length - 1) * powerBase10(length - 2);

    int numRecursive = numberOf1(strN+1);
    return numFirstDigit + numOthers + numRecursive;
}

int numberOf1Between1AndN(int n)
{
    if (n <= 0)
        return 0;
    char strN[50];
    sprintf(strN, "%d", n);
    return numberOf1(strN);
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << n << " " << numberOf1Between1AndN(n) << endl;
    }
    return 0;
}