// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

#include<iostream>

using namespace std;

struct BinaryTreeNode
{
    int m_nValues;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pFather;
};

BinaryTreeNode* FindNextNode(BinaryTreeNode* p_node)
{
    if (p_node == nullptr)
        return nullptr;
    BinaryTreeNode* next_node = nullptr;
    // 该节点有右节点
    if (p_node -> m_pRight != nullptr)
    {
        BinaryTreeNode* r_node = p_node -> m_pRight;
        while (r_node->m_pLeft != nullptr)
        {
            r_node = r_node -> m_pLeft;
        }
        next_node = r_node;
    }
    // 该节点无右节点，但存在父节点
    else if (p_node->m_pFather != nullptr)
    {
        // 该节点为父节点的 左子节点, 直接返回 父节点
        
        // 该节点为父节点的 右子节点, 一直找父节点，直到该父节点为其父节点的左子节点
       
        BinaryTreeNode* father_node = p_node->m_pFather;
        BinaryTreeNode* current_node = p_node;
        while(father_node != nullptr && current_node == father_node->m_pRight)
        {
            current_node = father_node;
            father_node = father_node->m_pFather;
        }
        next_node = father_node;
    }
    return next_node;
}


// ==================== 辅助代码用来构建二叉树 ====================
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_nValues = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
    pNode->m_pFather = nullptr;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;

        if(pLeft != nullptr)
            pLeft->m_pFather = pParent;
        if(pRight != nullptr)
            pRight->m_pFather = pParent;
    }
}

void PrintTreeNode(BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->m_nValues);

        if(pNode->m_pLeft != nullptr)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValues);
        else
            printf("left child is null.\n");

        if(pNode->m_pRight != nullptr)
            printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValues);
        else
            printf("right child is null.\n");
    }
    else
    {
        printf("this node is null.\n");
    }

    printf("\n");
}

void PrintTree(BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != nullptr)
    {
        if(pRoot->m_pLeft != nullptr)
            PrintTree(pRoot->m_pLeft);

        if(pRoot->m_pRight != nullptr)
            PrintTree(pRoot->m_pRight);
    }
}

void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

// ====================测试代码====================
void Test(char* testName, BinaryTreeNode* pNode, BinaryTreeNode* expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    BinaryTreeNode* pNext = FindNextNode(pNode);
    if(pNext == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void Test1_7()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);
    char* test_func = (char*)"Test1";
    Test(test_func, pNode8, pNode9);
    test_func = (char*)"Test2";
    Test(test_func, pNode6, pNode7);
    test_func = (char*)"Test3";
    Test(test_func, pNode10, pNode11);
    test_func = (char*)"Test4";
    Test(test_func, pNode5, pNode6);
    test_func = (char*)"Test5";
    Test(test_func, pNode7, pNode8);
    test_func = (char*)"Test6";
    Test(test_func, pNode9, pNode10);
    test_func = (char*)"Test7";
    Test(test_func, pNode11, nullptr);

    DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test8_11()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);

    char* test_func = (char*)"Test8";
    Test(test_func, pNode5, nullptr);
    test_func = (char*)"Test9";
    Test(test_func, pNode4, pNode5);
    test_func = (char*)"Test10";
    Test(test_func, pNode3, pNode4);
    test_func = (char*)"Test11";
    Test(test_func, pNode2, pNode3);

    DestroyTree(pNode5);
}

//        2
//         3
//          4
//           5
void Test12_15()
{
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    char* test_func = (char*)"Test12";
    Test(test_func, pNode5, nullptr);
    test_func = (char*)"Test13";
    Test(test_func, pNode4, pNode5);
    test_func = (char*)"Test14";
    Test(test_func, pNode3, pNode4);
    test_func = (char*)"Test15";
    Test(test_func, pNode2, pNode3);


    DestroyTree(pNode2);
}

void Test16()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    char* test_func = (char*)"Test16";
    Test(test_func, pNode5, nullptr);

    DestroyTree(pNode5);
}

int main(int argc, char* argv[])
{
    Test1_7();
    Test8_11();
    Test12_15();
    Test16();
}