// 面试题26：树的子结构
// 题目：输入两棵二叉树A和B，判断B是不是A的子结构。

// #include<iostream>

#include "/home/hadoop/VSProjects/offer_68/include/binaryTree.h"



// 匹配到B树的头节点， 再进行全匹配
bool tree2InTree1(BiTree pRoot1, BiTree pRoot2)
{
    if (pRoot2 == nullptr)
        return true;
    if (pRoot1 == nullptr)
        return false;
    if (!equalDouble(pRoot1->data, pRoot2->data))
        return false;
    return tree2InTree1(pRoot1->lchild, pRoot2->lchild) 
        && tree2InTree1(pRoot1->rchild, pRoot2->rchild);
}

bool hasSubTree(BiTree pRoot1, BiTree pRoot2)
{
    bool flag = false;
    if (pRoot1 != nullptr && pRoot2 != nullptr)
    {
        if (equalDouble(pRoot1->data, pRoot2->data))
            flag = tree2InTree1(pRoot1, pRoot2);
        if (!flag)
            flag = hasSubTree(pRoot1->lchild, pRoot2);
        if (!flag)
            flag = hasSubTree(pRoot1->rchild, pRoot2);
    }
    return flag;
}

int main()
{
    BiTree tree1 = Create_BiTree();
    PreOrder(tree1);
    BiTree tree2 = Create_BiTree();
    PreOrder(tree2);

    cout << hasSubTree(tree1, tree2) << endl;

    return 0;
}
