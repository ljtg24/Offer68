#include "/home/hadoop/VSProjects/Offer68/include/functools.h"
void delete2DMatrix(eleType** m, int rows)
{
    for (int i = 0; i < rows; ++i)
        delete[] m[i];
    delete[] m;
}