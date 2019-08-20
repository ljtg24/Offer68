#include <string>
#include <iostream>

using namespace std;

int confirmRange(const string& numStr, unsigned int frontIdx, unsigned int nextIdx)
{
    if (frontIdx < 0 || frontIdx >= numStr.size() || nextIdx < 0 || nextIdx >= numStr.size())
        return 0;
    // int num = stoi(numStr[frontIdx])*10 + stoi(numStr[nextIdx]);
    int num = (numStr[frontIdx]-'0')*10 + (numStr[nextIdx]-'0');
    // cout << num << endl;
    if (num >= 10 && num <= 25)
        return 1;
    return 0;
}

// 递归方法
int transformInteger2StringRecursive(const string& numStr, unsigned int idx)
{
    if (idx >= numStr.size())
        return 0;
    if (idx == (numStr.size()-1))
        return 1;
    return transformInteger2StringRecursive(numStr, idx+1) + 
            confirmRange(numStr, idx, idx+1)*transformInteger2StringRecursive(numStr, idx+2);
}

int transformInteger2StringRecursive(int number)
{
    if (number < 0)
        return -1;
    string numStr = to_string(number);
    // for (unsigned int i = 0; i < numStr.size(); ++i)
    //     cout << numStr[i] << " ";
    // cout << endl;

    return transformInteger2StringRecursive(numStr, 0);
}

// 自下而上
int GetTranlationCount(const string& numStr)
{
    int length = numStr.size();
    int* counts = new int[length];
    int count = 0;

    for (int i = length-1; i >= 0; --i)
    {
        if (i < length-1)
            count = counts[i+1];
        else
            count = 1;
        if (i < length-1)
        {
            int factor = confirmRange(numStr, i, i+1);
            if (factor == 1)
            {
                if (i < length-2)
                    count += counts[i+2];
                else
                    count += 1;
            }
        }
        counts[i] = count;
    }
    count = counts[0];
    delete[] counts;
    return count;
}

int GetTranlationCount(int number)
{
    if (number < 0)
        return -1;
    string numStr = to_string(number);
    return GetTranlationCount(numStr);
}

int main()
{
    cout << transformInteger2StringRecursive(12258) << endl;
    cout << GetTranlationCount(12258) << endl;
    return 0;
}