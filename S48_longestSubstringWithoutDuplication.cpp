#include <string>
#include <iostream>

using namespace std;

int longestSubstring(const string& str)
{
    int curLength = 0, maxLength = 0;
    int* position = new int[26];
    for (int i = 0; i < 26; ++i)
        position[i] = -1;
    for (int i = 0; i < str.size(); ++i)
    {
        int idx = position[str[i]-'a'];
        if (idx < 0 || i - idx > curLength)
            curLength++;
        else
        {
            if (curLength > maxLength)
                maxLength = curLength;
            curLength = i - idx;
        }
        position[str[i]-'a'] = i;
    }
    if (curLength > maxLength)
        maxLength = curLength;
    delete[] position;

    return maxLength;
}

int main()
{
    string s = "abcabf";
    cout << longestSubstring(s) << endl;
    return 0;
}