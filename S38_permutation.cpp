#include <iostream>
#include <cstdio>
using std::cout;
using std::endl;

void permutationCore(char* pStr, char* pBegin)
{
    if (*pBegin == '\0')
    {
        // cout << (*pStr) << endl;
        printf("%s\n", pStr);
    }
    else
    {
        for (char* pCh = pBegin; *pCh != '\0'; pCh++)
        {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;

            permutationCore(pStr, pBegin+1);

            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp; // 换回来，pCh+1与pBegin继续换
        }
    }
}

void permutation(char* pStr)
{
    if (pStr == nullptr)
        return;
    permutationCore(pStr, pStr);
}

int main()
{
    char a[] = "abc";
    char* pStr = a;
    permutation(pStr);
    return 0;
}