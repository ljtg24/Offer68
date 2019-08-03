#pragma once
#include<iostream>
#include<math.h>
#include<cstdio>
#include<stack>
#include<vector>
#include<typeinfo>
// #include"text_exception.h"

using namespace std;

typedef double eleType;
typedef struct BiTreeNode *BiTree;

// int (*str_process)(const char *__nptr);
// void init_str_process()
// {
//     if (typeid(eleType) == typeid(int))
//         str_process = atoi;
//     else
//     {
//         /* code */
//     }
     
// }

struct BiTreeNode
{
    eleType data;
    BiTreeNode* lchild;
    BiTreeNode* rchild;
};

BiTree NewNode(eleType x);
BiTree Create_BiTree(char s[]);
int Find(char s[],int left,int right);
BiTree Create_BiTree(char s[],int left,int right);
//先序扩展创建二叉树    ABD...C..
bool equalDouble(double d1, double d2);
BiTree Create_BiTree();

void RecurvePreOrder(BiTree T);
void PreOrder(BiTree T);
void RecurveMediumOrder(BiTree T);
void MediumOrder(BiTree T);
void RecurvePostOrder(BiTree T);
void PostOrder(BiTree T);