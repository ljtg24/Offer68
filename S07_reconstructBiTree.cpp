// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。

#include<iostream>

using namespace std;
struct BinaryTreeNode
{
    int m_nValues;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

BinaryTreeNode* ConstructBiTree(int* preorder, int* inorder, int length)
{
    if (preorder == nullptr || inorder == nullptr || length <= 0)
        return nullptr;
    
    return ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root -> m_nValues = rootValue;
    root -> m_pLeft = root -> m_pRight = nullptr;

    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder && *startPreorder == * startInorder)
            return root;
        else
            throw std::exception();
    }

    // 在中序遍历中找到根节点的值 
    int* rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue)
        ++rootInorder;
    if (rootInorder == endInorder && *rootInorder != rootValue)
        throw std::exception();
    
    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if (leftLength > 0)
    {
        // 构建左子树
        root -> m_pLeft =ConstructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder-1);
    }
    int rightLength = endInorder - rootInorder;
    if (rightLength > 0)
    {
        // 构建右子树
        root -> m_pRight =ConstructCore(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
    }
    
    return root;
}

// ====================测试代码====================
void printOrder(int* order, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << order[i];
    }
    cout << "\n";
}

void RecurvePreOrder(BinaryTreeNode* T)
{
    if (nullptr != T)
    {
        cout << T->m_nValues;
        RecurvePreOrder(T->m_pLeft);
        RecurvePreOrder(T->m_pRight);
    }
}

void RecurveMediumOrder(BinaryTreeNode* T)
{
    if (nullptr != T)
    {
        RecurveMediumOrder(T->m_pLeft);
        cout << T->m_nValues;
        RecurveMediumOrder(T->m_pRight);
    }
}


void Test(int* preorder, int* inorder, int length)
{
    BinaryTreeNode* root = nullptr;
    root = ConstructBiTree(preorder, inorder,length);
    if (root == nullptr)
        cout << "root is nullptr." << endl;
    else
    {
        cout << "preorder: ";
        printOrder(preorder, length);
        cout<< "RecurvePreOrder: ";
        RecurvePreOrder(root);
        cout << "\n";

        cout << "inorder: ";
        printOrder(inorder, length);
        cout << "RecurveMediumOrder: ";
        RecurveMediumOrder(root);
        cout << "\n";
    }
    cout << endl;
}

void Test1()
{
    cout << "\nTest1 begins.\n";

    int preorderArr[] = {1,2,4,7,3,5,6,8};
    int* preorder = preorderArr;
    int inorderArr[] = {4,7,2,1,5,3,8,6};
    int* inorder = inorderArr;
    Test(preorder, inorder, 8);

}

void Test2()
{
    cout << "\nTest2 begins.\n";
}

int main()
{
    Test1();
    return 0;
}
