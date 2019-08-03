// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。


#include<iostream>
using namespace std;

bool matchCore(char* str, char* pattern)
{
    if (*str == '\0' && *pattern == '\0')
        return true;
    if (*str != '\0' && *pattern == '\0')
        return false;

    if (*(pattern+1) == '*')
    {
        if (*str == *pattern || (*pattern == '.' && *str != '\0'))
            return matchCore(str+1, pattern) 
                || matchCore(str+1, pattern+2)
                || matchCore(str, pattern+2);
        else
            return matchCore(str, pattern+2);
    }
    if (*str == *pattern ||(*pattern == '.' && *str != '\0'));
        return matchCore(str+1, pattern+1);

    return false;
}

bool match(char* str, char* pattern)
{
    if (str == nullptr || pattern == nullptr)
        return false;
    return matchCore(str, pattern);
}

int main()
{
    char str[] = "aaab";
    char pattern[] = "*ab*ac*a.";
    cout << match(str, pattern)<<endl;
    return 0;
}