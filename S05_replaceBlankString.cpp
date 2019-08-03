// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

#include<iostream>
#include<cstring>
using namespace std;

void replaceBlank(char str[], int length)
{
    if (str == nullptr || length < 1)
        return;
    int blank_num = 0;
    int origin_len = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        ++origin_len;
        if (str[i] == ' ')
            ++blank_num;
        ++i;
    }
    cout << origin_len << ", " << blank_num << endl;
    int back_off = blank_num*(3-1);
    if (length < (origin_len + back_off))
        return;
    for (int i = origin_len-1; i >= 0; i--)
    {
        // cout << str[i] << endl;
        if (str[i] != ' ')
        {
            str[i+back_off] = str[i];
        }
        else
        {
            str[i+back_off] = '0';
            str[i+back_off-1] = '2';
            str[i+back_off-2] = '%';
            back_off = back_off -2;

        }
        
    }
    
}

// ====================测试代码====================
void Test(char* testName, char str[], int length, char expected[])
{
    if(testName != nullptr)
        cout << " begins: " << testName << endl;

    replaceBlank(str, length);

    if(expected == nullptr && str == nullptr)
        cout <<"passed.\n";
    else if(expected == nullptr && str != nullptr)
        cout <<"failed.\n";
    else if(strcmp(str, expected) == 0)
        cout <<"passed.\n";
    else
        cout <<"failed.\n";
}

// 空格在句子中间
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    char* test_func = (char*)"Test1";
    Test(test_func, str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    char* test_func = (char*)"Test2";
    Test(test_func, str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    char* test_func = (char*)"Test3";
    Test(test_func, str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    char* test_func = (char*)"Test4";
    Test(test_func, str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
    char* test_func = (char*)"Test5";
    Test(test_func, nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char str[length] = "";
    char* test_func = (char*)"Test6";
    Test(test_func, str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    char* test_func = (char*)"Test7";
    Test(test_func, str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    char* test_func = (char*)"Test8";
    Test(test_func, str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    char* test_func = (char*)"Test9";
    Test(test_func, str, length, "%20%20%20");
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
    Test8();
    Test9();

    return 0;
}