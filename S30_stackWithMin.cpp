// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
// 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。

#include<stack>
#include<assert.h>
#include<iostream>

template<typename T> class stackWithMin
{
public:
    stackWithMin(){};
    virtual ~stackWithMin(){};
    T& top();
    const T& top() const;
    void push(const T& value);
    void pop();
    const T& min() const;
    bool empty() const;
    int size() const;
private:
    std::stack<T> m_data;
    std::stack<T> m_min;
};

template<typename T> void stackWithMin<T>::push(const T& value)
{
    m_data.push(value);
    if (m_min.empty() || value < m_min.top())
        m_min.push(value);
    else
        m_min.push(m_min.top());
    
}
template<typename T> void stackWithMin<T>::pop()
{
    assert(m_data.size() > 0 && m_min.size() > 0);
    m_min.pop();
    m_data.pop(); 
}

template<typename T> const T& stackWithMin<T>::min() const
{
    assert(m_min.size()>0 && m_data.size()>0);
    return m_min.top(); 
}

template<typename T> T& stackWithMin<T>::top()
{
    return m_data.top();
}
template<typename T> const T& stackWithMin<T>::top() const
{
    return m_data.top();
}
template<typename T> bool stackWithMin<T>::empty() const
{
    return m_data.empty();
}
template<typename T> int stackWithMin<T>::size() const
{
    return m_data.size();
}

int main()
{
    stackWithMin<int> swm;
    int a[] = {4,2,7,3,5,1,2,10};
    for (auto item: a)
    {
        swm.push(item);
        std::cout << item << ": " << swm.min() << std::endl;
    }
    return 0;
}