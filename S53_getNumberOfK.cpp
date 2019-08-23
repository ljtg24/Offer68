#include <iostream>

using namespace std;

int getFirstK(int* data, int length, int num, int start, int end)
{
    if (start > end)
        return -1;
    int middle = (start + end) >> 1;
    if (data[middle] == num)
    {
        if (middle > 0 && data[middle-1] != num)
            return middle;
        else
            end = middle - 1;
    }
    else if (data[middle] > num)
        end = middle - 1;
    else
        start = middle + 1;
    return getFirstK(data, length, num, start, end);
}

int getLastK(int* data, int length, int k, int start, int end)
{
    if (start > end)
        return -1;
    int middle = (start + end) >> 1;
    if (data[middle] == k)
    {
        if (middle < length - 1 && data[middle+1] != k)
            return middle;
        else
            start = middle + 1;
    }
    else if (data[middle] > k)
        end = middle - 1;
    else
        start = middle + 1;
    return getLastK(data, length, k, start, end);
}

int getNumberOfK(int* data, int length, int k)
{
    int number = 0;
    if (data != nullptr && length > 0)
    {
        int firstPosition = getFirstK(data, length, k, 0, length-1);
        int lastPosition = getLastK(data, length, k, 0, length-1);
        if (firstPosition > -1 && lastPosition > -1)
            number = lastPosition - firstPosition + 1;
    }
    return number;
}

int main()
{
    int data[] = {1,2,3,3,3,3,4,5};
    cout << getNumberOfK(data, 8, 3) << endl;
    return 0;
}