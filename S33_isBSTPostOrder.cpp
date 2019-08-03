// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。

#include<iostream>
using namespace std;

bool isBSTPostOrder(int* numbers, int length)
{
    if (numbers == nullptr || length <= 0)
        return false;
    if (length == 1)
        return true;
    int* postNode = numbers+length-1;
    int* iterNode = numbers;
    while (*iterNode < *postNode && iterNode < postNode)
        ++iterNode;
    int left_length = iterNode - numbers > 0 ? iterNode-numbers:0;
    bool left_flag = true;
    if (left_length > 0)
        left_flag = isBSTPostOrder(numbers, left_length);

    int* rightNode = numbers + left_length;
    iterNode = rightNode;
    while (iterNode < postNode)
    {
        if (*iterNode < *postNode)
            return false;
        iterNode++;
    }
    int right_length = iterNode - rightNode > 0 ? iterNode-rightNode:0;
    bool right_flag = true;
    if (right_length > 0)
        right_flag = isBSTPostOrder(rightNode, right_length);
    return (left_flag&&right_flag);
}

int main()
{
    int a[] = {4,9,8,7,12,9,10};
    int* p = a;
    cout << isBSTPostOrder(p, 7) << endl;
    return 0;
}