#include<iostream>
#include "/home/hadoop/VSProjects/Offer68/include/binaryTree.h"

using namespace std;

// 二叉树深度
int getBiTreeDepth(BiTree pRoot)
{
    if (pRoot == nullptr)
        return 0;
    int left = getBiTreeDepth(pRoot->lchild);
    int right = getBiTreeDepth(pRoot->rchild);
    return (left > right) ? left:right;
}

// 判断平衡二叉树
// 法一： 平衡二叉树的最大深度和最小深度只差不超过1
int getBiTreeMinDepth(BiTree pRoot)
{
    if (pRoot == nullptr)
        return 0;
    int left = getBiTreeDepth(pRoot->lchild);
    int right = getBiTreeDepth(pRoot->rchild);
    return (left < right) ? left:right;
}
bool isBalancedSolution1(BiTree pRoot)
{
    int minDepth = getBiTreeMinDepth(pRoot);
    int maxDepth = getBiTreeDepth(pRoot);
    int diff = maxDepth-minDepth;
    if (diff >= -1 && diff <= 1)
        return true;
    return false;
}

//法二 平衡二叉树的子树也是平衡二叉树  如何避免递归的重复计算
bool isBalancedSolution2(BiTree pRoot, int* depth)
{
    if (pRoot == nullptr)
    {
        *depth = 0;
        return true;
    }
    int left, right;
    if (isBalancedSolution2(pRoot->lchild, &left) && isBalancedSolution2
    (pRoot->rchild, &right))
    {
        int diff = left - right;
        if (diff <= 1 and diff >= -1)
        {
            *depth = 1 + (left > right)?left:right;
            return true;
        }
    }
    return false;
}

bool isBalancedSolution2(BiTree pRoot)
{
    if (pRoot == nullptr)
        return true;
    int depth = 0;
    return isBalancedSolution2(pRoot, &depth);
}