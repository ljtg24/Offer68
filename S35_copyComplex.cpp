// 面试题35：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
// 结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。

#include "/home/hadoop/VSProjects/offer_68/include/complexListNode.h"


void colneNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while (pNode != nullptr)
    {
        ComplexListNode* cloneNode = new ComplexListNode();
        cloneNode->m_nValue = pNode->m_nValue;
        cloneNode->m_pNext = pNode->m_pNext;
        cloneNode->m_pSibling = nullptr;

        pNode->m_pNext = cloneNode;
        pNode = cloneNode->m_pNext;
    }
}

void connectSiblingNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while (pNode != nullptr)
    {
        ComplexListNode* pCloned = pNode->m_pNext;
        if (pNode->m_pSibling != nullptr)
        {
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
        }
        pNode = pCloned->m_pNext;
    }
}

ComplexListNode* reconnectNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    ComplexListNode* pClonedHead = nullptr;
    ComplexListNode* pClonedNode = nullptr;

    if (pNode != nullptr)
    {
        pClonedHead = pNode->m_pNext;
        pClonedNode = pClonedHead;

        pNode->m_pNext = pClonedNode->m_pNext; // 确认复制链表的头节点
        pNode = pNode->m_pNext;
    }
    while (pNode != nullptr)
    {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;

        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    return pClonedHead;
}

ComplexListNode* cloneComplexList(ComplexListNode* pHead)
{
    if (pHead == nullptr)
        return nullptr;
    colneNodes(pHead);
    connectSiblingNodes(pHead);
    return reconnectNodes(pHead);
}

int main()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    PrintList(pNode1);
    return 0;
}