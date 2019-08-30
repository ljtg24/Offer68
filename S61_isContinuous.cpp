#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void* arg1, const void* arg2)
{
    return *(int*)arg1 - *(int*)arg2;
}

bool isContinuous(int* data, int length)
{
    if (data == nullptr || length <= 0)
        return false;
    qsort(data, length, sizeof(int), compare);

    int zeroNums = 0;
    for (int i = 0; i < length && data[i] == 0; ++i)
        ++zeroNums;
    int numberOfGap = 0;
    int small = zeroNums;
    int big = small + 1;
    while (big < length)
    {
        if (data[small] == data[big])
            return false;
        numberOfGap += data[big] - data[small] - 1;
        small = big;
        big++;
    }
    return (zeroNums >= numberOfGap)?true:false;
}


int main()
{
    int a[] = {4,6,7,8,0};
    cout << isContinuous(a, 5) << endl;
    return 0;
}