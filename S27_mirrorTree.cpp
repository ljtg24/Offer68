// 面试题27：二叉树的镜像
// 题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。

// #include<iostream>

#include "/home/hadoop/VSProjects/Offer68/include/binaryTree.h"

void mirrorTreeRecursively(BiTree pRoot)
{
    if (pRoot == nullptr)
        return;
    if (pRoot->lchild == nullptr && pRoot->rchild == nullptr)
        return;
    BiTree temp = pRoot->lchild;
    pRoot->lchild = pRoot->rchild;
    pRoot->rchild = temp;

    if (pRoot->lchild != nullptr)
        mirrorTreeRecursively(pRoot->lchild);
    if (pRoot->rchild != nullptr)
        mirrorTreeRecursively(pRoot->rchild);
}

int main()
{
    BiTree pRoot = Create_BiTree();

    PreOrder(pRoot);
    mirrorTreeRecursively(pRoot);
    PreOrder(pRoot);

    return 0;
}