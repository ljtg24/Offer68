// 面试题34：二叉树中和为某一值的路径
// 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
// 有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

#include<vector>
#include<iostream>
#include "/home/hadoop/VSProjects/offer_68/include/binaryTree.h"
using namespace std;

void FindPath(BiTree root, int sum, vector<int>& path, int currentSum)
{
    bool isLeaf = (root->lchild==nullptr && root->rchild==nullptr);
    currentSum += root->data;
    path.push_back(root->data);

    if (currentSum == sum && isLeaf)
    {
        vector<int>::iterator iter;
        for (iter=path.begin(); iter != path.end(); ++iter)
            cout << *iter << " ";
        cout << "\n";
    }
    if (root->lchild != nullptr)
        FindPath(root->lchild, sum, path, currentSum);
    if (root->rchild != nullptr)
        FindPath(root->rchild, sum, path, currentSum);
    path.pop_back(); // 到叶节点了

}

void printEqualSum(BiTree root, int sum)
{
    if (root == nullptr)
        return;
    vector<int> path;
    int currentSum = 0;
    FindPath(root, sum, path, currentSum);
}

int main()
{
    BiTree root = Create_BiTree();
    printEqualSum(root, 16);
    return 0;
}