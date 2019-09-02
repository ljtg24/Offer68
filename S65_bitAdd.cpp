#include <iostream>

using namespace std;

int bitAdd(int num1, int num2)
{
    int sum, carry;
    while (num2 != 0)
    {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    }
    
    return num1;
}

int main()
{
    cout << bitAdd(15, 7) << endl;
    return 0;
}