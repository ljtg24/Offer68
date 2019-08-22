#include <iostream>

using namespace std;


int inversePairsCore(int* nums, int* copy, int start, int end)
{
    if (start == end)
    {
        copy[start] = nums[start];
        return 0;
    }
    int middle = (start + end) >> 1;
    int left = inversePairsCore(copy, nums, start, middle);
    int right = inversePairsCore(copy, nums, middle+1, end);

    int i = middle;
    int j = end;
    int endIndex = end;
    int count = 0;
    while (i >= start && j > middle)
    {
        if (nums[i] > nums[j])
        {
            copy[endIndex--] = nums[i--];
            count += (j-middle);
        }
        else
        {
            copy[endIndex--] = nums[j--];
        }
    }
    for (; i >= start; --i)
        copy[endIndex--] = nums[i];
    for (; j > middle; --j)
        copy[endIndex--] = nums[j];

    return left + right + count;
}

int inversePairs(int* nums, int length)
{
    if (nums == nullptr || length <= 0)
        return 0;
    int* copy = new int[length];
    for (int i = 0; i < length; ++i)
        copy[i] = nums[i];
    int count = inversePairsCore(nums, copy, 0, length-1);

    delete[] copy;
    return count;
}

int main()
{
    int nums[] = {7, 5, 6, 4};
    cout << inversePairs(nums, 4) << endl;
    return 0;
}