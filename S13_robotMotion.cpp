// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

#include<iostream>
#include<cstring>

using namespace std;

int getDigitSum(int a)
{
    int sum = 0;
    while (a > 0)
    {
        sum += a%10;
        a /= 10;
    }
    return sum;
}

bool check(int rows, int cols, int row, int col, int k_threshold, bool* visited)
{
    int sum = getDigitSum(row) + getDigitSum(col);
    if (row < rows && row >= 0 && col < cols && col >= 0 && sum <= k_threshold && !visited[row*cols+col])
        return true;
    return false;
}

int movingCountCore(int rows, int cols, int row, int col, int k_threshold, bool* visited)
{
    int count = 0;
    if (check(rows, cols, row, col, k_threshold, visited))
    {
        visited[row*cols+col] = true;
        count = 1 + movingCountCore(rows, cols, row+1, col, k_threshold, visited)
                + movingCountCore(rows, cols, row, col+1, k_threshold, visited)
                + movingCountCore(rows, cols, row-1, col, k_threshold, visited)
                + movingCountCore(rows, cols, row, col-1, k_threshold, visited);
    }
    return count;
}

int movingCount(int rows, int cols, int k_threshold)
{
    if (rows < 1 || cols < 1 || k_threshold < 0)
        return 0;
    bool* visited = new bool[rows*cols];
    memset(visited, 0, rows*cols);
    int count = movingCountCore(rows, cols, 0, 0, k_threshold, visited);

    delete[] visited;
    return count;
}

int main()
{
    cout << movingCount(10, 10, 1) << endl;
    return 0;
}