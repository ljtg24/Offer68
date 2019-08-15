#include <iostream>
#include <math.h>
using namespace std;
int countOfIntegers(int digits)
{
    if (digits == 1)
        return 10;
    return 9*(int)pow10(digits-1);
}

int getBeginNumber(int digits)
{
    if (digits == 1)
        return 0;
    return (int)pow10(digits-1);
}

int numberOfIndex(int index)
{
    if (index < 0)
        return -1;
    int digits = 1;
    //bool flag = true;
    while (true)
    {
        int count = countOfIntegers(digits);
        if (index < count*digits)
        {
            int number = getBeginNumber(digits) + index/digits;
            int fromRight = digits - index%digits;
            for (int i = 1; i < fromRight; ++i)
                number /= 10;
            return number%10;
        }
        index -= count*digits;
        ++digits;
    }
}

int main()
{
    for (auto a: {10,190,1000, 0, 1})
    cout << a << " " << numberOfIndex(a) << endl; 
    return 0;
}