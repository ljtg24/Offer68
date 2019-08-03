// 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
// 照递增排序的。例如输入图3.11中的链表1和链表2，则合并之后的升序链表如链
// 表3所示。


#include<iostream>
#include "/home/hadoop/VSProjects/offer_68/include/listNode1.h"

using namespace std;

ListNode* mergeList(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == nullptr)
        return pHead2;
    if (pHead2 == nullptr)
        return pHead2;
    ListNode* pMergeHead = nullptr;
    if (pHead1->m_nValue <= pHead2->m_nValue)
    {
        pMergeHead = pHead1;
        pMergeHead->m_pNext = mergeList(pHead1->m_pNext, pHead2);
    }
    else
    {
        pMergeHead = pHead2;
        pMergeHead->m_pNext = mergeList(pHead1, pHead2->m_pNext);
    }
    return pMergeHead;
}

int main()
{
    ListNode* head = initNode(1);
    ListNode* temp_node = head;
    for (int i = 3; i < 10; i+=2)
    {
        
        ListNode* pNode = initNode(i);
        temp_node->m_pNext = pNode;
        temp_node = temp_node->m_pNext;
    }
    ListNode* head2 = initNode(0);
    temp_node = head2;
    for (int i = 2; i < 9; i+=2)
    {
        
        ListNode* pNode = initNode(i);
        temp_node->m_pNext = pNode;
        temp_node = temp_node->m_pNext;
    }
    printList(&head);
    printList(&head2);
    ListNode* pMerged = nullptr;
    pMerged = mergeList(head, head2);
    printList(&pMerged);
    temp_node->m_pNext = nullptr;
    deleteList(head);
    deleteList(head2);
    return 0;
}
