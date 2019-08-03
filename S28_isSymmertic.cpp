// 面试题28：对称的二叉树
// 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
// 它的镜像一样，那么它是对称的。
// #include<iostream>

#include "/home/hadoop/VSProjects/offer_68/include/binaryTree.h"

bool isSymmerticCore(BiTree pRoot1, BiTree pRoot2)
{
    if (pRoot2 == nullptr && pRoot1 == nullptr)
        return true;
    if (pRoot1 == nullptr || pRoot2 == nullptr)
        return false;
    if (pRoot1->data != pRoot2->data)
        return false;
    return isSymmerticCore(pRoot1->lchild, pRoot2->rchild)
        && isSymmerticCore(pRoot1->rchild, pRoot2->lchild);
}

bool isSymmertic(BiTree pRoot)
{
    return isSymmerticCore(pRoot, pRoot);
}