#include<iostream>
#include"/home/hadoop/VSProjects/offer_68/include/binaryTree.h"

using namespace std;

void serialize(BiTree root, ostream& stream)
{
    if (root == nullptr)
    {
        stream << "$,";
        return;
    }
    stream << root->data << ",";
    serialize(root->lchild, stream);
    serialize(root->rchild, stream);
}


bool ReadStream(istream& stream, int* number)
{
    if (stream.eof())
        return false;
    char buffer[32];
    buffer[0] = '\0';

    char ch;
    stream >> ch;
    int i = 0;
    while(!stream.eof() && ch != ',')
    {
        buffer[i++] = ch;
        stream >> ch;
    }

    bool isNumeric = false;
    if(i > 0 && buffer[0] != '$')
    {
        *number = atoi(buffer);
        isNumeric = true;
    }

    return isNumeric;
}

void deserialize(BiTree* root, istream& stream)
{
    int number;
    if (ReadStream(stream, &number))
    {
        *root = NewNode(number);
        deserialize(&((*root)->lchild), stream);
        deserialize(&((*root)->rchild), stream);
    }
}

int main()
{
    BiTree root = Create_BiTree();
    // ostream stream;
    // serialize(&root, )
}