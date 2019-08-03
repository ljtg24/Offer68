// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

#include<iostream>
#include<cstring>

using namespace std;

bool Increment(char* digits, int length)
{
    bool flag = false;
    int isTakeOver = 0;
    for (int i = length-1; i >=0; --i)
    {
        int sum = digits[i]-'0'+isTakeOver;
        // isTakeOver = 0;
        if (i == length-1)
            ++sum;
        if (sum >= 10)
        {
            if (i == 0)
                flag = true;
            else
            {
                sum -= 10;
                isTakeOver = 1;
                digits[i] = sum + '0';
            }
        }
        else
        {
            digits[i] = sum + '0';
            break;
        }        
    }
    return flag;
}

void printDigits(const char* digits, int length)
{
    bool startPrint = false;
    for (int i = 0; i < length; ++i)
    {
        if (!startPrint && digits[i] != '0')
            startPrint = true;
        if (startPrint)
            cout << digits[i];
    }
    cout << endl;
}

void print1ToMaxOfNDigits(int n)
{
    if (n < 1)
        return;
    char* digits = new char[n+1];
    memset(digits, '0', n);
    digits[n] = '\0';
    while(!Increment(digits, n))
        printDigits(digits, n);

    delete[] digits;
}

// 递归方法
void print1ToMaxOfNDigitsRecursively(char* digits, int length, int index)
{
    if (index == length-1)
    {
        printDigits(digits, length);
        return;
    }
    for (int i = 0; i < 10; ++i)
    {
        digits[index+1] = i + '0';
        print1ToMaxOfNDigitsRecursively(digits, length, index+1);
    }
}

void print1ToMaxOfNDigits_2(int n)
{
    if (n < 1)
        return;
    char* digits = new char[n+1];
    digits[n] = '\0';

    for (int i = 0; i < 10; ++i)
    {
        digits[0] = i + '0';
        print1ToMaxOfNDigitsRecursively(digits, n, 0);
    }
    delete[] digits;
}
int main()
{
    // print1ToMaxOfNDigits(-1);
    // print1ToMaxOfNDigits(2);
    print1ToMaxOfNDigits_2(-1);
    print1ToMaxOfNDigits_2(2);
    return 0;
}