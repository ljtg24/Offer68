// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H

#include<iostream>
#include<cstring>

using namespace std;

bool hasPathCore(const char* matrix, int row, int col, int i, int j, const char* str, int& path_length, bool* visited)
{
    if (str[path_length] == '\0')
        return true;
    bool has_path = false;
    if (i < row && i >= 0 && j < col && j >=0 && matrix[i*col+j] == str[path_length] && !visited[i*col+j])
    {
        ++path_length;
        visited[i*col+j] = true;

        has_path = hasPathCore(matrix, row, col, i+1, j, str, path_length, visited)
                || hasPathCore(matrix, row, col, i-1, j, str, path_length, visited)
                || hasPathCore(matrix, row, col, i, j+1, str, path_length, visited)
                || hasPathCore(matrix, row, col, i, j-1, str, path_length, visited);
        if (!has_path)
        {
            --path_length;
            visited[i*col+j] = false;
        }
    }
    return has_path;
}

bool FindPathInMatrix(char* matrix, int row, int col, char* str)
{
    if (matrix == nullptr || row < 1 || col < 1)
        return false;
    // bool flag = false;
    bool* visited = new bool[row*col];
    memset(visited, 0, row*col);
    int path_length = 0;
    
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (hasPathCore(matrix, row, col, i, j, str, path_length, visited))
                return true;
        }
    }
    delete[] visited;
    return false;
}

int main()
{
    char matrix[] = "abtgcfcsjdeh";
    // {'a', 'b', 't', 'g', 'c', 'f', 'c', 's', 'j', 'd', 'e', 'h'}
    int row = 3, col = 4;
    char str[] = "bfce";
    cout << FindPathInMatrix(matrix, row, col, str) << endl;

    return 0;
}