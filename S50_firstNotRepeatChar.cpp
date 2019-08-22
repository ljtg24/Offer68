#include <iostream>
#include <limits>
using namespace std;


class CharStatistics
{
private:
    int occurrence[256];
    int index;
public:
    CharStatistics():index(0)
    {
        for (int i = 0; i < 256; ++i)
            occurrence[i] = -1;
    }

    void insert(char ch)
    {
        if (occurrence[ch] == -1)
            occurrence[ch] = index;
        if (occurrence[ch] >= 0)
            occurrence[ch] = -2;
        ++index; //*
    }

    char firstAppear()
    {
        char ch = '\0';
        int minIndex = numeric_limits<int>::max();
        for (int i = 0; i < 256; ++i)
        {
            if (occurrence[i] >= 0 && occurrence[i] < minIndex)
            {
                ch = (char)i;
                minIndex = occurrence[i];
            }
        }
        return ch;
    }
};

char firstNotRepeatChar(char* pString)
{
    if (pString == nullptr)
        return '\0';
    const unsigned int tableSize = 256;
    char hashTable[tableSize];
    for (unsigned int i = 0; i < tableSize; ++i)
        hashTable[i] = 0;
    char* pHashKey = pString;
    while ((*pHashKey)!='\0')
        hashTable[*(pHashKey++)]++;
    pHashKey = pString;
    while (*pHashKey != '\0')
    {
        if (hashTable[*pHashKey] == 1)
            return *pHashKey;
        pHashKey++;
    }
    return '\0';
}



int main()
{
    // char* pString = "abaccdeff";
    // cout << firstNotRepeatChar(pString) << endl;
    CharStatistics cs;
    string str = "google";
    for (int i = 0; i < str.size(); ++i)
    {
        cs.insert(str[i]);
        cout << str[i] << " " << cs.firstAppear() << endl;
    }
    return 0;
}