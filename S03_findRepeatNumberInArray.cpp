#include<iostream>
#include<cstdio>
using namespace std;

bool findRepeatNumber(int arr[], int length, int* repeatNumbers);

// int main()
// {
//     bool find = false;
//     int repeat = -1;
//     int Arr[14] = {6,2,3,3,7,4,1,0,5,4,3,8,3,9};
//     find = findRepeatNumber(Arr, 14, &repeat);
//     if (find)
//         cout << "find duplicate number:" << repeat << endl;

//     return 0;
// }

bool findRepeatNumber(int arr[], int length, int* repeatNumbers)
{
    if (arr == nullptr || length ==0)
        return false;

    for (int i = 0; i < length; i++)
    {
        if (arr[i] < 0 || arr[i] > length-1)
            return false;
    }
    for (int i = 0; i < length; i++)
    {
        while(arr[i] != i){
            if (arr[i] == arr[arr[i]])
            {
                *repeatNumbers = arr[i];
                return true;
            }
            // swap arr[i] and arr[arr[i]]
            int tmp = arr[i];
            arr[i] = arr[tmp];
            arr[tmp] = tmp;
        }
        
    }

    // cout << "test" << endl;
    return false;
}


// ====================测试代码====================
bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
            return true;
    }

    return false;
}

void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);

    int duplication;
    bool validInput = findRepeatNumber(numbers, lengthNumbers, &duplication);

    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, expectedExpected, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}

// 重复的数字是数组中最小的数字
void test1()
{
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplications[] = { 1 };
    char* test_func = (char*)"Test1";
    test(test_func, numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2()
{
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplications[] = { 4 };
    char* test_func = (char*)"Test2";
    test(test_func, numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    char* test_func = (char*)"Test3";
    test(test_func, numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    char* test_func = (char*)"Test4";
    test(test_func, numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    char* test_func = (char*)"Test5";
    test(test_func, numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6()
{
    int* numbers = nullptr;
    int duplications[] = { -1 }; // not in use in the test function
    char* test_func = (char*)"Test6";
    test(test_func, numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

int  main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}