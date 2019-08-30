#include <iostream>

using namespace std;

int maxDiff(int* data, int length)
{
    if (data == nullptr || length < 2)
        return 0;
    int minNum = data[0];
    int maxDiffNum = data[1] - minNum;
    for (int i = 2; i < length; ++i)
    {
        if (data[i-1] < minNum)
            minNum = data[i-1];
        int curDiff = data[i] - minNum;
        if (curDiff > maxDiffNum)
            maxDiffNum = curDiff;
    }
    return maxDiffNum;
}

int main()
{
    int data[] = {9,11,8,5,7,12,16,14};
    cout << maxDiff(data, 8) << endl;
    return 0;
}