#include "/home/hadoop/VSProjects/offer_68/include/functools.h"
void delete2DMatrix(eleType** m, int rows)
{
    for (int i = 0; i < rows; ++i)
        delete[] m[i];
    delete[] m;
}