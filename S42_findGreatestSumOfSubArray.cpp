#include <iostream>
#include <exception>
#include <vector>

using namespace std;

int getGreatestSum(const vector<int> numbers)
{
    if (numbers.size() == 0)
        throw exception();
    int maxSum = INT32_MIN;
    // cout << maxSum << endl;
    int curSum = 0;
    for (vector<int>::const_iterator iter = numbers.begin(); iter != numbers.end(); ++iter)
    {
        curSum += *iter;
        if (curSum > maxSum)
            maxSum = curSum;
        if (curSum < 0)
            curSum = 0;
    }
    return maxSum;
}



int main()
{
    int N;
    while(cin >> N)
    {
        vector<int> a;
        for (int i = 0; i < N; ++i)
        {
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        // for (vector<int>::iterator iter = a.begin(); iter != a.end(); ++iter)
        // {
        //     cout << *iter << " ";
        // }
        // cout << "\n";
        cout << getGreatestSum(a) << endl;
    }

    // int a[] = {-2, 3, 3, 4, -5, 4, -3};
    // int* p = a;
    // cout << getGreatestSum(p, 7) << endl;
    return 0;
}