#include <iostream>
#include <vector>

using namespace std;

void multiply(const vector<double>& arrayA, vector<double>& array2)
{
    int length1 = arrayA.size();
    int length2 = array2.size();

    if (length1 == length2 && length2 > 1)
    {
        array2[0] = 1;
        for (int i = 1; i < length1; ++i)
            array2[i] = array2[i-1] * arrayA[i-1];
        int temp = 1;
        for (int i = length2-2; i >= 0; --i)
        {
            temp *= arrayA[i+1];
            array2[i] *= temp;
        }
    }
}

int main()
{
    vector<double> array1 = {1,2,3,4,5};
    vector<double> array2(array1.size(), 1);
    multiply(array1, array2);

    for (auto item : array2)
        cout << item << " ";
    cout << endl;
    return 0;
}