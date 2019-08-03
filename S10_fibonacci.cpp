//==================================================================

// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。

#include<iostream>
#include<assert.h>

using namespace std;

// 递归
long long Fibonacci_1(unsigned int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return Fibonacci_1(n-1) + Fibonacci_1(n-2);
}

// 循环
long long Fibonacci_2(unsigned int n)
{
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    long long temp = 0;
    long long pre_fib = 0;
    long long post_fib = 1;

    for (int i = 2; i <= n; i++)
    {
        temp = pre_fib + post_fib;
        pre_fib = post_fib;
        post_fib = temp;
    }

    return post_fib;
}

// 动态规划
long long Func(unsigned int n, long long *p)
{
    assert(n>=0);
    if (p[n] != 0 || n == 0)
        return p[n];
    if (n == 1)
        p[n] = 1;
    else
    {
        long long x = Func(n-1, p);
        long long y = Func(n-2, p);
        p[n] = x + y;
    }
    
    return p[n];
}

long long Fibonacci_3(unsigned int n)
{
    if (n <= 0)
        return 0;
    long long fib_cache[n+1]={0};
    // fib_cache[1] = 1;
    long long *p;
    p = fib_cache;


    return Func(n, p);
}


// ====================测试代码====================
void Test(int n, int expected)
{
    if(Fibonacci_1(n) == expected)
        cout<<"Test for "<<n<<" in solution1 passed.\n";
    else
        cout<<"Test for "<<n<<" in solution1 failed.\n";

    if(Fibonacci_2(n) == expected)
        cout<<"Test for "<<n<<" in solution2 passed.\n";
    else
        cout<<"Test for "<<n<<" in solution2 failed.\n";

    if(Fibonacci_3(n) == expected)
        cout<<"Test for "<<n<<" in solution3 passed.\n";
    else
        cout<<"Test for "<<n<<" in solution3 failed.\n";
}

int main(int argc, char* argv[])
{
    Test(0, 0);
    Test(1, 1);
    Test(2, 1);
    Test(3, 2);
    Test(4, 3);
    Test(5, 5);
    Test(6, 8);
    Test(7, 13);
    Test(8, 21);
    Test(9, 34);
    Test(10, 55);

    Test(40, 102334155);

    return 0;
}
