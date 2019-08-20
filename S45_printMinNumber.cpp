#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxNumberLength = 10;
char* strCombine1 = new char[maxNumberLength*2 + 1];
char* strCombine2 = new char[maxNumberLength*2 + 1];

int compare(const void* strNumber1, const void* strNumber2)
{
    strcpy(strCombine1, *(const char**)strNumber1);
    strcat(strCombine1, *(const char**)strNumber2);

    strcpy(strCombine2, *(const char**)strNumber2);
    strcat(strCombine2, *(const char**)strNumber1);
    return strcmp(strCombine1, strCombine2);
}

void printMinNumber(int* numbers, int length)
{
    if (numbers == nullptr || length <= 0)
        return ;
    char** strNumbers = (char**)(new int[length]);
    for (int i = 0; i < length; ++i)
    {
        strNumbers[i] = new char[maxNumberLength+1];
        sprintf(strNumbers[i], "%d", numbers[i]);
    }
    qsort(strNumbers, length, sizeof(char*), compare);
    for (int i = 0; i < length; ++i)
        printf("%s", strNumbers[i]);
    printf("\n");
    for (int i = 0; i < length; ++i)
        delete[] strNumbers[i];
    delete[] strNumbers;
}

int main()
{
    int number[] = {123, 321, 5, 132};
    int* p = number;
    printMinNumber(p, 4);

    return 0;
}