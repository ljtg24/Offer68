#include <iostream>
#include "/home/hadoop/VSProjects/Offer68/include/listNode1.h"

using namespace std;

int getListLength(ListNode* pHead)
{
    int length = 0;
    ListNode* pNode = pHead;
    while (pNode != nullptr)
    {
        ++length;
        pNode = pNode->m_pNext;
    }
    return length;
}

ListNode* findFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == nullptr || pHead2 == nullptr)
        return nullptr;
    int length1 = getListLength(pHead1);
    int length2 = getListLength(pHead2);

    int lengthDif = 0;
    ListNode* pNode1 = nullptr;
    ListNode* pNode2 = nullptr;
    if (length1 > length2)
    {
        pNode1 = pHead1;
        pNode2 = pHead2;
        lengthDif = length1 - length2;
    }
    else
    {
        pNode1 = pHead2;
        pNode2 = pHead1;
        lengthDif = length2 - length1;        
    }

    for (int i = 0; i < lengthDif; ++i)
        pNode1 = pNode1->m_pNext;
    while ((pNode1 != nullptr) && (pNode2 != nullptr) && (pNode1!=pNode2))
    {
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }
    ListNode* firstCommonNode = pNode1;
    return firstCommonNode;
}

int main()
{
    return 0;
}