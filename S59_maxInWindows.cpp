#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxInWindows(int* data, int length, int k)
{
    vector<int> maxW;
    if (data != nullptr && k > 0 && k <= length)
    {
        deque<int> idxs;
        // 确定前k个数中的最大值
        for (int i = 0; i < k; ++i)
        {
            while (!idxs.empty() && data[i] > data[idxs.back()])
                idxs.pop_back();
            idxs.push_back(i);
        }
        for (int i = k; i < length; ++i)
        {
            maxW.push_back(data[idxs.front()]);
            while (!idxs.empty() && data[i] > data[idxs.back()])
                idxs.pop_back();
            if (!idxs.empty() && idxs.front() <= i - k)
                idxs.pop_front();
            idxs.push_back(i);
        }
        maxW.push_back(data[idxs.front()]);
    }
    return maxW;
}

// 题目二：队列的最大值
// 函数 max, push_back 和 pop_front 的时间复杂度都是O(1)

template<typename T>class QueueWithMax
{
private:
    struct InternalData
    {
        T number;
        int index;
    };
    deque<InternalData> data;
    deque<InternalData> maximums;
    int curIdx; 
public:
    QueueWithMax():curIdx(0){};
    void push_back(T number)
    {
        while (!maximums.empty() && number > maximums.back().number)
            maximums.pop_back();
        InternalData internalData = {number, curIdx};
        maximums.push_back(internalData);
        data.push_back(internalData);
        ++curIdx; 
    }

    void pop_front()
    {
        if (maximums.empty())
            throw new std::exception();
        if (maximums.front().index == data.front().index)
            maximums.pop_front();
        data.pop_front();
    }

    T max()
    {
        return maximums.front().number;
    }
};

int main()
{
    int data[] = {2,3,4,2,6,2,5,1};
    vector<int> res;
    res = maxInWindows(data, 8, 3);
    for (auto ele: res)
        cout << ele << " ";
    cout << "\n";
    QueueWithMax<int> qwm;
    for (auto ele: data)
    {
        qwm.push_back(ele);
        cout << qwm.max() << " ";
    }
    cout << "\n";
    qwm.pop_front();
    cout << qwm.max() <<endl;
        
    return 0;
}