#include <iostream>
#include <list>
using namespace std;

int lastRemaining(unsigned int n, unsigned int m)
{
    if (m < 1 || n < 1)
        return -1;
    unsigned int i = 0;
    list<int> data;
    for (; i < n; ++i)
        data.push_back(i);
    list<int>::iterator cur_iter = data.begin();
    while (data.size() > 1)
    {
        for (int i = 0; i < m; ++i)
        {
            cur_iter++;
            if (cur_iter == data.end())
                cur_iter = data.begin();
        }
        list<int>::iterator next = ++cur_iter;
        if (next == data.end())
            next = data.begin();
        --cur_iter;
        data.erase(cur_iter);
        cur_iter = next;
    }
    return (*cur_iter);
}

int main()
{
    int n = 10, m = 3;
    cout << n << " " << m << " " << lastRemaining(n, m) << endl;
    return 0;
}