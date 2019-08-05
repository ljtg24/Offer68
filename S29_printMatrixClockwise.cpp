// 面试题29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

#include<iostream>
#include "/home/hadoop/VSProjects/Offer68/include/functools.h"

using namespace std;

void printMatrixCircle(int** numbers, int rows, int cols, int start)
{
    int endX = cols - start - 1;
    int endY = rows - start - 1;
    // 从左往右打印一行
    for (int i = start; i <= endX; ++i)
    {
        int number = numbers[start][i];
        cout << number << " ";
    }
    // 从上往下打印一行
    if (start < endY)
    {
        for (int i = start+1; i <= endY; ++i)
        {
            int number = numbers[i][endX];
            cout << number << " ";
        }
    }
    // 从右往左打印一行
    if (start < endX && start < endY)
    {
        for (int i = endX-1; i >= start; --i)
        {
            int number = numbers[endY][i];
            cout << number << " ";
        }
    }
    // 从下往上打印一行
    if (start < endY-1 && start < endX)
    {
        for (int i = endY-1; i >= start+1; --i)
        {
            int number = numbers[i][start];
            cout << number << " ";
        }
    }
}

void printMatrixClockwisely(int** numbers, int rows, int cols)
{
    if (numbers == nullptr || rows <= 0 || cols <= 0)
        return;
    int start = 0;
    while (start*2 < rows && start *2 < cols)
    {
        printMatrixCircle(numbers, rows, cols, start);
        ++start;
    }
    cout << endl;
}

int main()
{
    int **value = new int* [4];
    for (int i = 0; i < 4; ++i)
        value[i] = new int[4];
    for (int i = 0; i < 4*4; ++i)
        value[i/4][i%4] = i;
    // int numbers[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    // int* p = &numbers[0][0];

    printMatrixClockwisely(value, 4, 4);
    delete2DMatrix(value, 4);
    return 0;
}