// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。

#include <iostream>
#include <exception>
#include <vector>
#include <set>
#include <functional>

using namespace std;

typedef multiset<int, greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator setIterator;

int Partition(int* numbers, int length, int start, int end)
{
    if (numbers == nullptr || length <= 0 || start < 0 || end >= length)
        throw new exception();
    int i_start = start, j_end = end;
    int temp_num = numbers[i_start];
    int index = i_start;  // 将start作为判断点
    while (i_start < j_end)
    {
        while (i_start < j_end)
        {
            while (i_start < j_end && numbers[j_end] > temp_num)
                --j_end;
            if (i_start < j_end)
            {
                numbers[i_start] = numbers[j_end];
                index = j_end;
            }
            while (i_start < j_end && numbers[i_start] < temp_num)
                ++i_start;
            if (i_start < j_end)
            {
                numbers[j_end] = numbers[i_start];
                index = i_start;
            }
        }
    }
    numbers[index] = temp_num;
    return index;
}

void getLeastNumbers(int* numbers, int* output, int length, int k) 
{
    if (numbers == nullptr || length <= 0 || output == nullptr || k <= 0 || k > length)
        return;
    int start = 0, end = length - 1;
    int index = Partition(numbers, length, start, end);
    while (index != k-1)
    {
        if (index > k-1)
        {
            end = index - 1;
            index = Partition(numbers, length, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(numbers, length, start, end);
        }
    }
    // for (int i = 0; i < 10; ++i)
    //         cout << numbers[i] << " ";
    //     cout << endl;
    for (int i = 0; i < k; ++i)
        output[i] = numbers[i];
    // return index;
}

void getKLeastNumbers(const vector<int>& data, intSet& leastNumbers, int k)
{
    if (data.size() < k || k <= 0)
        return ;
    vector<int>::const_iterator iter = data.begin();
    for (; iter != data.end(); ++iter)
    {
        if (leastNumbers.size() < k)
            leastNumbers.insert(*iter);
        else
        {
            setIterator greatIter = leastNumbers.begin();
            if (*iter < *(leastNumbers.begin()))
            {
                leastNumbers.erase(greatIter);
                leastNumbers.insert(*iter);
            }
        }
    }
}

int main()
{
    int a[] = {1,4,6,7,2,3,9,8,5,0};
    int b[] = {1,4,6,7,2};
    int *p = &a[0], *q = b;
    getLeastNumbers(p, q, 10, 5);
    for (int i = 0; i < 10; ++i)
        cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < 5; ++i)
        cout << b[i] << " ";
    cout << endl;
    return 0;
}

    