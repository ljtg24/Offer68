#include<vector>
#include<algorithm>
#include<iostream>
#include<exception>
#include<functional>

using namespace std;

template<typename T> class DynamicArray
{
private:
    vector<T> min;  // 最大堆，左
    vector<T> max;  // 最小堆，右
public:
    void insert(T num)
    {
        if (((min.size() + max.size()) & 1) == 0) // 数据流长度为偶数
        {
            if (max.size() > 0 && num < max[0])
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<T>());
                num = max[0];
                pop_heap(max.begin(), max.end(), less<T>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<T>());
        }
        else
        {
            if (min.size() > 0 && num > min[0])
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<T>());
                num = min[0];
                pop_heap(min.begin(), min.end(), greater<T>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<T>());
        }
    }

    T getMedian()
    {
        int size = min.size() + max.size();
        if (size == 0)
            throw new exception();
        T median = 0;
        if ((size & 1) == 0)
            median = (min[0] + max[0]) / 2;
        else
            median = min[0];
        return median;
    }
};


int main()
{
    DynamicArray<double> da;
    double a[] = {1.0,3.0,5,2,0,8,6,9,7,4};
    for (auto num: a)
    {
        da.insert(num);
        cout << num << " " << da.getMedian() << endl;
    }
    
    return 0;
}