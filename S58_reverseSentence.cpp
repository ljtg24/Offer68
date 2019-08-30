#include <iostream>
#include<cstring>
#include <stdio.h>
using namespace std;

// 题一
void Reverse(char* pStart, char* pEnd)
{
    if (pStart == nullptr || pEnd == nullptr)
        return ;
    while (pStart < pEnd)
    {
        char temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;
        pStart++, pEnd--;
    }
}

char* reverseSentence(char* pData)
{
    if (pData == nullptr)
        return nullptr;
    char* pStart = pData;
    char* pEnd = pData;
    while (*pEnd != '\0')
        pEnd++;
    --pEnd;
    Reverse(pStart, pEnd);
    
    pStart = pEnd = pData;
    while (*pStart != '\0')
    {
        if (*pStart == ' ')
        {
            pStart++;
            pEnd++;
        }
        else if (*pEnd == ' ' && *pEnd == '\0')
        {
            Reverse(pStart, pEnd);
            pStart = ++pEnd;
        }
        else 
            pEnd++;
    }
    return pData;
}

// 题二 思路 把string分成两部分，前k个和余下的len-k个，分别对着两部分进行翻转，再翻转整个字符串
char* leftRotateString(char* pStr, int n)
{
    if (pStr == nullptr || n <= 0)
        return pStr;
    int nLength = static_cast<int>(strlen(pStr));
    if (nLength > 0 && n < nLength)
    {
        char* pFirstStart = pStr;
        char* PFirstEnd = pStr+n-1;
        char* pOthersStart = pStr + n;
        char* pOthersEnd = pStr + nLength - 1;

        // 翻转前面n个字符
        Reverse(pFirstStart, PFirstEnd);
        // 翻转余下nLength - n个字符
        Reverse(pOthersStart, pOthersEnd);

        //翻转整个字符串
        Reverse(pFirstStart, pOthersEnd);
    }
    return pStr;
}


int main()
{
    char* pStr = "abcdefg";
    
    return 0;
}