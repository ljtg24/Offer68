#include <iostream>
#include "/home/hadoop/VSProjects/Offer68/include/binaryTree.h"

using namespace std;
BiTree kthNodeCore(BiTree pRoot, unsigned int& k)
{
    BiTree target = nullptr;
    if (pRoot->lchild != nullptr)
        target = kthNodeCore(pRoot->lchild, k);
    if (target == nullptr)
    {
        if (k == 1)
            return pRoot;
        k--;
    }
    if (target == nullptr && pRoot->rchild != nullptr)
        target  =kthNodeCore(pRoot->rchild, k);
    return target;
}

BiTree kthNode(BiTree pRoot, unsigned int k)
{
    if (pRoot == nullptr || k == 0)
        return nullptr;
    return kthNodeCore(pRoot, k);
}

int main()
{
    BiTree root = Create_BiTree();
    int k = 3;
    cout << kthNode(root, k)->data << endl;
    return 0;
}