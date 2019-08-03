#include<iostream>
#include<cstdio>
using namespace std;
// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。

//从左下角开始查找，找到所在列后再用二分法进行查找

bool find(int* matrix, int rows, int cols, int number)
{
    
    if (matrix == nullptr || rows < 0 || cols < 0)
        return false;
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << i << "," << j << ": " << *(matrix+i*cols+j) << endl;
    //     }
    // }
    rows = rows - 1; 
    int i_col = 0;
    while (i_col < cols)
    {
        cout << i_col << endl;
        if (*(matrix+rows*cols+i_col) == number)  // matrix[rows, i_col]
            return true;
        if (*(matrix+rows*cols+i_col) > number)  // 在该列中进行查找
        {
            int start = 0;
            int end = rows - 1;  // rows 的位置大于number，不需比较
            while (start <= end)
            {
                int middle = ((end - start)>>1) + start;
                int tmp = *(matrix+middle*cols+i_col); // matrix[middle, i_col]
                cout << " start " << start << " end: " << end << " middle: " << middle << " tmp: " << tmp << endl;
                if (start == end)
                {
                    if (tmp != number)
                        break;
                }
                if (tmp == number)
                {
                    return true;
                }
                if (number > tmp)
                {
                    start = middle + 1;
                }
                else
                {
                    end = middle;
                }
                    
                
            }
            return false;
        }
        i_col++;
    }

    return false;
}

// ====================测试代码====================
void Test(char* testName, int* matrix, int rows, int columns, int number, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    bool result = find(matrix, rows, columns, number);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数在数组中
void Test1()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    char* test_func = (char*)"Test1";
    Test(test_func, (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数不在数组中
void Test2()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    char* test_func = (char*)"Test2";
    Test(test_func, (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最小的数字
void Test3()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    char* test_func = (char*)"Test3";
    Test(test_func, (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最大的数字
void Test4()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    char* test_func = (char*)"Test4";
    Test(test_func, (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最小的数字还小
void Test5()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    char* test_func = (char*)"Test5";
    Test(test_func, (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最大的数字还大
void Test6()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    char* test_func = (char*)"Test6";
    Test(test_func, (int*)matrix, 4, 4, 16, false);
}

// 鲁棒性测试，输入空指针
void Test7()
{
    char* test_func = (char*)"Test7";
    Test(test_func, nullptr, 0, 0, 16, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}

