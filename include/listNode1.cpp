#include"/home/hadoop/VSProjects/offer_68/include/listNode1.h"

void printList(ListNode** pHead)
{
    ListNode* pNode = * pHead;
    if (pNode == nullptr)
        cout << "空指针。" << endl;
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
