#include <vector> 
#include <iostream>

using namespace std;

bool validMoreThanHalfNum(vector<int> numbers, int currentNum)
{
    unsigned int count = 0;
    vector<int>::iterator iter;
    for (iter = numbers.begin(); iter != numbers.end(); ++iter)
    {
        if (*iter == currentNum)
            count++;
    }
    return (count > numbers.size()/2);
}


int MoreThanHalfNum_Solution(vector<int> numbers) {
    if (numbers.size() < 0)
        return 0;
    
    int count = 0;
    
    vector<int>::iterator iter = numbers.begin();
    int currentNum = *iter;
    for (; iter != numbers.end(); ++iter)
    {
        //cout << *iter << " ";
        if (*iter == currentNum)
            count++;
        else
            count--;
        if (count < 0)
        {
            count = 1;
            currentNum = *iter;
        }
    }
    if (!validMoreThanHalfNum(numbers, currentNum))
        return 0;
    return currentNum;
}

int main()
{
    vector<int> numbers{1,1,1,1,2,2,1,2};
    cout << MoreThanHalfNum_Solution(numbers) << endl;
    return 0;
}