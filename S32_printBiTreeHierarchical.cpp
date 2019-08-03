// 面试题32（一）：不分行从上往下打印二叉树
// 题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。

// 面试题32（二）：分行从上到下打印二叉树
// 题目：从上到下按层打印二叉树，同一层的结点按从左到右的顺序打印，每一层
// 打印到一行。

// 面试题32（三）：之字形打印二叉树
// 题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺
// 序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
// 其他行以此类推。

#include<stack>
#include<deque>
#include<iostream>
#include "/home/hadoop/VSProjects/offer_68/include/binaryTree.h"
using namespace std;

// 不分行从上到下打印二叉树。
void printFromTopToButtom(BiTree root)
{
    if (root == nullptr)
        return;
    deque<BiTree> btDeque;
    btDeque.push_back(root);
    while(btDeque.size())
    {
        BiTree pNode = btDeque.front();
        btDeque.pop_front();
        cout << pNode->data << ' ';
        if (pNode->lchild != nullptr)
            btDeque.push_back(pNode->lchild);
        if (pNode->rchild != nullptr)
            btDeque.push_back(pNode->rchild);
    }
    cout << endl;
}

void printFromTopToButtomHierarchical(BiTree root)
{
    if (root == nullptr)
        return;
    deque<BiTree> btDeque;
    btDeque.push_back(root);
    int toBePrint = 1;
    int nextLevel = 0;
    while (btDeque.size())
    {
        BiTree pNode = btDeque.front();
        btDeque.pop_front();
        cout << pNode->data << " ";
        toBePrint--;
        if (pNode->lchild != nullptr)
        {
            btDeque.push_back(pNode->lchild);
            nextLevel++;
        }
        if (pNode->rchild != nullptr)
        {
            btDeque.push_back(pNode->rchild);
            nextLevel++;
        }
        if (toBePrint == 0)
        {
            toBePrint = nextLevel;
            cout << "\n";
            nextLevel = 0;
        }
    }
}

void printBiTreeWithZShape(BiTree root)
{
    if (root == nullptr)
        return;
    stack<BiTree> Level[2];
    int current = 0;
    int next = 1;
    Level[0].push(root);
    while(!Level[0].empty() || !Level[1].empty())
    {
        BiTree pNode = Level[current].top();
        Level[current].pop();
        cout << pNode->data << ' ';
        if (current == 0)
        {
            if (pNode->lchild != nullptr)
                Level[next].push(pNode->lchild);
            if (pNode->rchild != nullptr)
                Level[next].push(pNode->rchild);
        }
        if (current == 1)
        {
            if (pNode->rchild != nullptr)
                Level[next].push(pNode->rchild);
            if (pNode->lchild != nullptr)
                Level[next].push(pNode->lchild);
        }
        if (Level[current].empty())
        {
            cout << "\n";
            current = 1 - current;
            next = 1 - next;
        }
    }
}

int main()
{
    BiTree root = Create_BiTree();
    printFromTopToButtom(root);
    printFromTopToButtomHierarchical(root);
    printBiTreeWithZShape(root);
    return 0;
}