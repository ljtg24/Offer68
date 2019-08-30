#include <iostream>
using namespace std;

bool findNumbersWithSum(int* numbers, int length, int sum, int* num1, int* num2)
{
    if (numbers == nullptr || length <= 0)
        return false;
    int start = 0, end = length - 1;
    while (start < end)
    {
        long long curSum = numbers[start] + numbers[end];
        if (curSum == sum)
        {
            *num1 = numbers[start];
            *num2 = numbers[end];
            return true;
        }
        else if (curSum > sum)
            end--;
        else 
            start++;
    }
    return false;
}


// 题二
void printContinuousSequence(int small, int big)
{
    for (int i = small; i <= big; ++i)
        cout << i << " ";
    cout << endl;
}

void findContinousSequence(int sum)
{
    if (sum < 3)
        return ;
    int small = 1, big = 2;
    int middle = (sum+1) >> 1;
    int curSum = small +big;
    while (small < middle)
    {
        if (curSum == sum)
            printContinuousSequence(small, big);
        while (curSum > sum && small < big)
        {
            curSum -= small;
            small++;
            if (curSum == sum)
                printContinuousSequence(small, big);
        }
        big++;
        curSum += big;
    }
}

int main()
{
    int a[6] = {1,3,5,8,10,15};
    int num1 = 0, num2 = 0;
    if (findNumbersWithSum(a, 6, 15, &num1, &num2))
        cout << num1 << " " << num2 << endl;
    else 
        cout << "no.\n";
    findContinousSequence(15);
    return 0;
}
