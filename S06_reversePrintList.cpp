// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

#include<iostream>
#include<stack>
using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};

ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->m_nKey = value;
    pNode->m_pNext = nullptr;

    return pNode;
}
void PrintList(ListNode* pHead)
{
    cout << "PrintList starts.\n";
    
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        cout<<pNode->m_nKey<<"\t";
        pNode = pNode->m_pNext;
    }

    cout<<"\nPrintList ends.\n";
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
        exit(1);
    }

    pCurrent->m_pNext = pNext;
}

void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

void reversePrint(ListNode* pHead)
{
    stack<ListNode*> nodes;
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    while(!nodes.empty())
    {
        pNode = nodes.top();
        cout << pNode->m_nKey << '\t';
        nodes.pop();
    }
}

void reversePrint_recursively(ListNode* pHead)
{
    ListNode* pNode = pHead;
    if (pNode != nullptr)
    {
        if (pNode->m_pNext != nullptr)
        {
            reversePrint_recursively(pNode->m_pNext);
        }
        cout << pNode->m_nKey << '\t';
    }
}

// ====================测试代码====================
void Test(ListNode* pHead)
{
    PrintList(pHead);
    reversePrint(pHead);
    cout << "\n";
    reversePrint_recursively(pHead);
}

// 1->2->3->4->5
void Test1()
{
    cout << "\nTest1 begins.\n";

    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1);

    DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test2()
{
    cout<<"\nTest2 begins.\n";

    ListNode* pNode1 = CreateListNode(1);

    Test(pNode1);

    DestroyList(pNode1);
}

// 空链表
void Test3()
{
    cout<<"\nTest3 begins.\n";

    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}