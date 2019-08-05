// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。

#include<iostream>
#include "/home/hadoop/VSProjects/Offer68/include/listNode1.h"

using namespace std;

ListNode* meetNode(ListNode* pHead)
{
    if (pHead == nullptr)
        return nullptr;
    ListNode* pSlow = pHead->m_pNext;
    if (pSlow == nullptr)
        return nullptr;
    ListNode* pQuick = pSlow->m_pNext;
    while (pQuick != nullptr && pSlow != nullptr)
    {
        if (pQuick == pSlow)
            return pQuick;
        pSlow = pSlow->m_pNext;
        pQuick = pQuick->m_pNext;
        if (pQuick != nullptr)
            pQuick = pQuick->m_pNext;
    }
    return nullptr;
}

ListNode* entryNodeOfloop(ListNode* pHead)
{
    ListNode* meet = meetNode(pHead);
    if (meet == nullptr)
        return nullptr;
    ListNode* ptr_1 = meet;
    unsigned int loop_len = 1;
    while (ptr_1->m_pNext != meet)
    {
        ++loop_len;
        ptr_1 = ptr_1->m_pNext;
    }
    cout << "loop_len: " << loop_len << endl;
    ptr_1 = pHead;
    for (int i = 0; i < loop_len; ++i)
        ptr_1 = ptr_1->m_pNext;
    ListNode* ptr_2 = pHead;
    while (ptr_1 != ptr_2)
    {
        ptr_1 = ptr_1->m_pNext;
        ptr_2 = ptr_2->m_pNext;
    }
    return ptr_1;
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    ListNode* head = initNode(0);
    ListNode** pHead;
    pHead = &head;
    ListNode* temp_node = head;
    ListNode* pEntry = nullptr;
    for (int i = 0; i < 9; ++i)
    {
        
        ListNode* pNode = initNode(a[i]);
        if (i == 3)
            pEntry = pNode;
        temp_node->m_pNext = pNode;
        temp_node = temp_node->m_pNext;
    }
    cout << temp_node->m_nValue << endl;
    temp_node->m_pNext = pEntry;
    ListNode* entry = entryNodeOfloop(head);
    if (entry != nullptr)
        cout << "loop 入口： " << entry->m_nValue << endl;
    else
        cout << "返回空指针. " << endl;
    // printList(&head);
    temp_node->m_pNext = nullptr;
    deleteList(head);
    return 0;
}
