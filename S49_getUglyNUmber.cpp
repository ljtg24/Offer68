#include <iostream>

using namespace std;

int Min(int num1, int num2, int num3)
{
    int min = (num1 < num2)?num1:num2;
    min = (min < num3)?min:num3;

    return min;
}

int getUglyNumber(int index)
{
    if (index <= 0)
        return 0;
    int* uglyNumbers = new int[index];
    uglyNumbers[0] = 1;
    int curIndex = 1;
    int* pMultiply2 = uglyNumbers;
    int* pMultiply3 = uglyNumbers;
    int* pMultiply5 = uglyNumbers;

    while (curIndex < index)
    {
        int min = Min(*pMultiply2*2, *pMultiply3*3, *pMultiply5*5);
        uglyNumbers[curIndex] = min;

        if (*pMultiply2*2 <= uglyNumbers[curIndex])
            ++pMultiply2;
        if (*pMultiply3*3 <= uglyNumbers[curIndex])
            ++pMultiply3;
        if (*pMultiply5*5 <= uglyNumbers[curIndex])
            ++pMultiply5;
        ++curIndex;
    }
    int ugly = uglyNumbers[curIndex-1];
    delete[] uglyNumbers;
    return ugly;
}

bool isUgly(int number)
{
    if (number % 2 == 0)
        number /= 2;
    if (number % 3 == 0)
        number /= 3;
    if (number % 5 == 0)
        number /= 5;
    return (number == 1)?true:false;
}

int main()
{
    for (int i = 10; i < 20; ++i)
    {
        cout << i << " " << getUglyNumber(i) << endl;
    }
    // cout << getUglyNumber(7) << endl;
    return 0;
}