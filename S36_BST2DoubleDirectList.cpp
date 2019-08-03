// 面试题36：二叉搜索树与双向链表
// 题目：输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求
// 不能创建任何新的结点，只能调整树中结点指针的指向。

#include<iostream>
#include "/home/hadoop/VSProjects/offer_68/include/binaryTree.h"

using namespace std;

void convert(BiTree root, BiTree* pLastNodeInList)
{
    if (root == nullptr)
        return;
    BiTree pCurrent = root;
    if (pCurrent->lchild != nullptr)
        convert(pCurrent->lchild, pLastNodeInList);
    
    pCurrent->lchild = (*pLastNodeInList);
    if ((*pLastNodeInList) != nullptr)
        (*pLastNodeInList)->rchild = pCurrent;
    (*pLastNodeInList) = pCurrent;

    if (pCurrent->rchild != nullptr)
        convert(pCurrent->rchild, pLastNodeInList);
}

BiTree BST2DoubleList(BiTree root)
{
    if (root == nullptr)
        return nullptr;
    BiTree pLastNodeInList = nullptr;
    convert(root, &pLastNodeInList); // 此时pLastNodeInList指向双向链表的尾部

    BiTree pListHead = pLastNodeInList;
    while (pListHead != nullptr && pListHead->lchild != nullptr)
        pListHead = pListHead->lchild;
    return pListHead;
}

int main()
{
    BiTree root = Create_BiTree();
    BiTree pListHead = BST2DoubleList(root);

    BiTree pNode = pListHead;
    BiTree rNode = nullptr;
    while(pNode != nullptr)
    {
        cout << pNode->data << " ";
        if (pNode->rchild == nullptr)
            rNode = pNode;
        pNode = pNode->rchild;
    }
    cout << "\n";
    while(rNode != nullptr)
    {
        cout << rNode->data << " ";
        rNode = rNode->lchild;
    }
    cout << endl;
    return 0;
}