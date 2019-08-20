#include <iostream>
#include <math.h>

using namespace std;

int getMaxValue(const int* values, int rows, int cols)
{
    if (values == nullptr || rows <= 0 || cols <= 0)
        return 0;
    int* maxValues = new int[cols];
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            int up = 0, left = 0;
            if (i > 0) 
                up = maxValues[j];
            if (j > 0)
                left = maxValues[j-1];
            maxValues[j] = (int)max(left, up) + values[i*cols + j];
        }
    }
    int maxValue = maxValues[cols-1];

    delete[] maxValues;
    return maxValue;
}

int main()
{
    int rows = 4;
    int cols = 5;
    int* nums = new int[rows*cols];
    
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            nums[i*cols+j] = (i*cols+j)%6+1;
            cout << nums[i*cols+j] << " ";
        }
        cout << "\n";
    }
        
        
            
    // int a[][5] = {1,2,3,4,5,
    //     5,4,6,7,8,
    //     1,2,3,2,4,
    //     4,2,1,4,3};
    // int** p = &a;
    std::cout << getMaxValue(nums, 4 ,5) << std::endl;

    delete[] nums;
    return 0;

}