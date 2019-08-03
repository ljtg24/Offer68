// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

#include<iostream>

using namespace std;

// 方法1 当n为负数时出现死循环
int numberOf1_1(int n)
{
    int count = 0;
    while (n)
    {
        if (n&1)
            ++count;
        n = n >> 1;
    }
    return count;
}

// 常规解法 
int numberOf1_2(int n)
{
    int count = 0;
    unsigned int flag = 1; //保证flag为整数

    while (flag)
    {
        if (n&flag)
            ++count;
        flag = flag << 1;
    }
    return count;
}

// 解法3
int numberOf1_3(int n)
{
    int count = 0;
    while(n)
    {
        ++count;
        n = n&(n-1);
    }
    return count;
}

int main()
{
    cout << numberOf1_1(10) << endl;
    cout << numberOf1_2(10) << ' ' << numberOf1_3(10) << endl;
    // cout << "number)f1_1(-10): "<<endl;
    // cout << numberOf1_1(-10) << endl;
    return 0;
}