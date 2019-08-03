// 面试题18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点。

#include<iostream>
using namespace std;
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
void deleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if (!pListHead || !pToBeDeleted)
        return;
    // 要删除的节点不是尾节点
    if (pToBeDeleted->m_pNext != nullptr)
    {
        cout<<pToBeDeleted->m_nValue<<endl;
        ListNode* pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNext->m_nValue;
        pToBeDeleted->m_pNext = pNext->m_pNext;

        delete pNext;
        pNext = nullptr;
    }
    //链表只有一个节点，删除头节点，同时也是尾节点
    else if ((*pListHead) == pToBeDeleted)
    {
        *pListHead = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
    // 删除的节点是尾节点
    else
    {
        ListNode* pNode = *pListHead;
        while(pNode->m_pNext != pToBeDeleted)
            pNode = pNode->m_pNext;
        pNode->m_pNext = nullptr;

        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
    
}
void printList(ListNode** pHead)
{
    ListNode* pNode = * pHead;
    while (pNode)
    {
        cout << pNode->m_nValue << ' ';
        pNode = pNode->m_pNext;
    }
    cout << endl;
}

ListNode* initNode(int nvalue)
{
    ListNode* pNode = new ListNode();
    pNode->m_nValue = nvalue;
    pNode->m_pNext = nullptr;

    return pNode;
} 

void deleteList(ListNode* pHead)
{
    ListNode* preNode = pHead;
    ListNode* postNode = nullptr;
    while(preNode!=nullptr)
    {
        postNode = preNode->m_pNext;
        delete preNode;
        preNode = nullptr;

        preNode = postNode;
    }
}


void deleteRepetitive(ListNode** pHead)
{
    if (*pHead == nullptr || pHead == nullptr)
        return;
    ListNode* preNode = nullptr;
    ListNode* sNode = *pHead;
    
    while (sNode!=nullptr)
    {
        bool isRepeated = false;
        ListNode* pNode = sNode->m_pNext;
        if (pNode!=nullptr && sNode->m_nValue == pNode->m_nValue)
            isRepeated = true;
        if (!isRepeated)
        {
            preNode = sNode;
            sNode = sNode->m_pNext;
        }
        else
        {
            int value = sNode->m_nValue;
            ListNode* toBeDeleteNode = sNode;
            while (toBeDeleteNode!=nullptr && toBeDeleteNode->m_nValue == value)
            {
                pNode = toBeDeleteNode->m_pNext;

                delete toBeDeleteNode;
                toBeDeleteNode = nullptr;

                toBeDeleteNode = pNode;
            }
            if (preNode == nullptr)
                *pHead = pNode; // 头指针指向的重复数据
            else
                preNode->m_pNext = pNode;
            sNode = pNode;
        }
    }
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,8};
    ListNode* head = initNode(1);
    // ListNode** pHead;
    // pHead = &head;
    ListNode* temp_node = head;
    
    for (int i = 0; i < 9; ++i)
    {
        
        ListNode* pNode = initNode(a[i]);
        temp_node->m_pNext = pNode;
        temp_node = temp_node->m_pNext;
    }
    // printList(&head);
    // ListNode* pToBeDeleted = head; // initNode(0)
    // cout << pToBeDeleted->m_nValue << endl;
    // deleteNode(&head, pToBeDeleted);
    deleteRepetitive(&head);
    printList(&head);
    deleteList(head);

    return 0;
}