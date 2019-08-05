// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。

#include<iostream>
// #include"/home/hadoop/VSProjects/offer_68/include/listNode1.h"
#include "/home/hadoop/VSProjects/Offer68/include/listNode1.h"
using namespace std;

ListNode* reverseList(ListNode* pHead)
{
    if (pHead == nullptr)
        return nullptr;
    ListNode* pFront = nullptr;
    ListNode* pMid = pHead;

    while (pMid != nullptr)
    {
        ListNode* pBack = pMid->m_pNext;
        pMid->m_pNext = pFront;
        pFront = pMid;
        pMid = pBack;
    }
    return pFront;
}

ListNode* Reverse(ListNode* pHead, ListNode** reversedHead)
{
    if (pHead->m_pNext == nullptr)
    {
        (*reversedHead) = pHead;
        return *reversedHead;
    }
    ListNode* pNode = Reverse(pHead->m_pNext, reversedHead);
    pNode->m_pNext = pHead;
    return pHead;
}

ListNode* reverseListRecursive(ListNode* pHead)
{
    if (pHead == nullptr)
        return nullptr;
    ListNode* reversedHead = nullptr;
    ListNode* pNode = Reverse(pHead, &reversedHead);
    pNode->m_pNext = nullptr;

    return reversedHead;
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    ListNode* head = initNode(0);
    // ListNode* reversedHead = nullptr;
    ListNode* temp_node = head;
    
    for (int i = 0; i < 9; ++i)
    {
        
        ListNode* pNode = initNode(a[i]);
        temp_node->m_pNext = pNode;
        temp_node = temp_node->m_pNext;
    }
    // ListNode* head2 = reverseList(head);
    ListNode* head2 = reverseListRecursive(head);
    printList(&head2);
    deleteList(head2);
    return 0;
}
