#pragma once
#include<iostream>
using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

void printList(ListNode** pHead);
ListNode* initNode(int nvalue);
void deleteList(ListNode* pHead);