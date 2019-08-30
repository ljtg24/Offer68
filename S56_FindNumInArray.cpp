#include <iostream>

using namespace std;

//题一：数组中只出现一次的数
bool isBit1(int num, unsigned int idx)
{
    num = num >> idx;
    return (num&1);
}

unsigned int findFirstBits1(int num)
{
    int idx = 0;
    while ((num&1) == 0 && (idx < 8*sizeof(int)))
    {
        num = num >> 1;
        idx++;
    }
    return idx;
}

void findNumAppearingOnce(int* numbers, int length, int* num1, int* num2)
{
    if (numbers == nullptr || length < 2)
        return ;
    int resExclusiveOr = 0;
    for (int i = 0; i < length; ++i)
        resExclusiveOr ^= numbers[i];
    int indexOfFirst1 = findFirstBits1(resExclusiveOr);
    for (int i = 0; i < length; ++i)
    {
        if (isBit1(numbers[i], indexOfFirst1))
            *num1 ^= numbers[i];
        else
            *num2 ^= numbers[i];
    }
}

// 题二
int findNumAppearintOnce_2(int* numbers, int length)
{
    if (numbers == nullptr || length <= 0)
        throw new exception();
    int bitSum[32] = {0};
    for (int i = 0; i < length; ++i)
    {
        int bitMask = 1;
        for (int j = 31; j >=0; --j)
        {
            int bit = numbers[i] & bitMask;
            if (bit != 0)
                bitSum[j]+=1;
            bitMask = bitMask << 1;
        }
    }
    int res = 0;
    for (int i = 0; i < 32; ++i)
    {
        res = res << 1;
        res += bitSum[i]%3;
    }
    return res;
}


int main()
{ 
    int a[6] = {1,4,6,6,1,11};
    int num1 = 0;
    int num2 = 0;
    findNumAppearingOnce(a, 6, &num1, &num2);
    cout << num1 << " " << num2 << endl;

    int b[10] = {11,11,35,11,35,35,76,76,24,76};
    cout << findNumAppearintOnce_2(b, 10); 
    return 0;
}