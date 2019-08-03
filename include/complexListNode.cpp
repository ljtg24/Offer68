#include<iostream>
#include "/home/hadoop/VSProjects/offer_68/include/complexListNode.h"
using std::cout;
using std::endl;

ComplexListNode* CreateNode(int nValue)
{
    ComplexListNode* pNode = new ComplexListNode();
    
    pNode->m_nValue = nValue;
    pNode->m_pNext = nullptr;
    pNode->m_pSibling = nullptr;

    return pNode;
}

void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling)
{
    if(pNode != nullptr)
    {
        pNode->m_pNext = pNext;
        pNode->m_pSibling = pSibling;
    }
}

void PrintList(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        std::cout<<"The value of this node is: " << pNode->m_nValue << std::endl;

        if(pNode->m_pSibling != nullptr)
            cout << "The value of its sibling is: " << pNode->m_pSibling->m_nValue << endl;
        else
            cout << "This node does not have a sibling.\n";

        cout<< "\n";

        pNode = pNode->m_pNext;
    }
}