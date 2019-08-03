// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
// 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
// 4、3、5、1、2就不可能是该压栈序列的弹出序列。

//卡特兰树

#include<iostream>
#include<stack>

using namespace std;

bool isPopOrder(const int* pPush, const int* pPop, int length)
{
    bool flag = false;
    if (pPush != nullptr || pPop != nullptr)
    {
        const int* pPushNext = pPush;
        const int* pPopNext = pPop;
        stack<int> assistStack;
        while (pPopNext-pPop < length)
        {
            while (assistStack.empty() || assistStack.top() != *pPopNext)
            {
                if (pPushNext-pPush >= length)
                    break;
                assistStack.push(*pPushNext);
                pPushNext++;
            }
            if (assistStack.top() != *pPopNext)
                break;
            assistStack.pop();
            ++pPopNext;
        }
        if (pPopNext-pPop == length && pPushNext - pPush == length)
            return true;
    }
    return flag;
}

int main()
{
    int a[] = {1,2,3,4,5};
    int b[] = {4,5,2,3,1};
    cout << isPopOrder(a, b, 5) << endl;
}