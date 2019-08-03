// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
// 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
// 值为4的结点。

#include<iostream>
#include "/home/hadoop/VSProjects/offer_68/include/listNode1.h"
using namespace std;

ListNode* findKthTotail(ListNode* pHead, unsigned int k)
{
    if (pHead == nullptr)
        return nullptr;
    ListNode* pFront = pHead;
    ListNode* pBack = nullptr;

    for (unsigned int i = 0; i < k-1; ++i)
    {
        pFront = pFront->m_pNext;
        if (pFront == nullptr)
        {
            // cout << "链表长度小于k." << endl;
            return nullptr;  // 链表长度小于k
        }
            
    }
    pBack = pHead;
    while (pFront->m_pNext != nullptr)
    {
        pFront = pFront->m_pNext;
        pBack = pBack->m_pNext;
    }
    return pBack;
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    ListNode* head = initNode(0);
    ListNode** pHead;
    pHead = &head;
    ListNode* temp_node = head;
    
    for (int i = 0; i < 9; ++i)
    {
        
        ListNode* pNode = initNode(a[i]);
        temp_node->m_pNext = pNode;
        temp_node = temp_node->m_pNext;
    }
    unsigned int k = 5;
    ListNode* kTail = findKthTotail(head, 10);
    if (kTail != nullptr)
        cout << "k=" << k << ", kTail=" << kTail->m_nValue << endl;
    else
        cout << "返回空指针. " << endl;
    printList(&head);
    deleteList(head);
    return 0;
}

