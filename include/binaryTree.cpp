/* 
    the functions of create binary Tree reference from 
    https://blog.csdn.net/linyuan703/article/details/81224483
 */
#include "/home/hadoop/VSProjects/Offer68/include/binaryTree.h"

// extern int prev1 = INT8_MIN;

BiTree NewNode(eleType x)
{
    BiTree p = new BiTreeNode();
    p->data = x;
    p->lchild = nullptr;
    p->rchild = nullptr;
    // cout << p->data << endl;
    
    return p;
}

//广义表创建二叉树     A(B(D,),C(E,F(,H)))
BiTree Create_BiTree(char s[])
{
    int k=0,top=-1;
    BiTree path[100],p;
    for(int i=0;s[i]!='\0';i++){
        switch(s[i]){
            case '(':   path[++top]=p;  k=1;    break;
            case ',':   k=2;    break;
            case ')':   top--;  break;
        }
        if(isalpha(s[i]) || isdigit(s[i])) // isalpha
        {
            // cout << s[i] << endl;
            p=NewNode(s[i]-48);
            if(k==1)
                path[top]->lchild=p;
            else if(k==2)
                path[top]->rchild=p;
        }
    }
    return path[0];
}

//递归创建二叉树    A(B(D,),C(E,F(,H)))
int Find(char s[],int left,int right)
{
    int k=0;
    for(int i=left;i<=right;i++){
        if(s[i]=='(')
            k++;
        if(s[i]==')')
            k--;
        if(s[i]==',' && k==1)
            return i;
    }    
    return left;
} 

BiTree Create_BiTree(char s[],int left,int right)
{
    int mid;
    if(left>right)
        return NULL;
    mid=Find(s,left,right);
    BiTree root=NewNode(s[left]);
    root->lchild=Create_BiTree(s,left+2,mid-1);
    root->rchild=Create_BiTree(s,mid+1,right-1);
    return root; 
}

bool equalDouble(double d1, double d2)
{
    if ((d1-d2 > -10e-6) && (d1-d2)<10e-6)
        return true;
    return false;
}

//先序扩展创建二叉树    ABD...C..
BiTree Create_BiTree()
{
    BiTree root;
    // char c=getchar();
    eleType c;
    (cin >> c).get();
    // if(c==-1)
    if (typeid(eleType) == typeid(int) && c == -1)
        return NULL;
    if (typeid(eleType) == typeid(double) && equalDouble(c, -1))
        return NULL;
    root=NewNode(c);
    root->lchild=Create_BiTree();
    root->rchild=Create_BiTree();
    
    return root; 
}

//根据先序和中序遍历确定二叉树    先序：abdfgceh    中序：fdgbache

int Find(char in[],int start,int end,char x)
{
    for(int i=start;i<=end;i++)
        if(in[i]==x)
            return i;
    return -1;
} 

BiTree Create_BiTree(char pre[],int s1,int e1,char in[],int s2,int e2)
{
    BiTree root=NewNode(pre[s1]);
    int k=Find(in,s2,e2,pre[s1]);
    if(k!=s2)
        root->lchild=Create_BiTree(pre,s1+1,s1+(k-s2),in,s2,k-1);
    if(k!=e2)
        root->rchild=Create_BiTree(pre,s1+(k-s2)+1,e1,in,k+1,e2);
    return root; 
}
void RecurvePreOrder(BiTree T)
{
    if (nullptr != T)
    {
        cout << T->data << " ";
        RecurvePreOrder(T->lchild);
        RecurvePreOrder(T->rchild);
    }
}

void PreOrder(BiTree T)
{
    stack<BiTree> s;
    BiTree p=T;
    while(p != nullptr || !s.empty())
    {
        while(p != nullptr)
        {
            cout << p->data << " ";
            s.push(p);
            p = p->lchild;
        }
        if (!s.empty()){
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void RecurveMediumOrder(BiTree T)
{
    if (nullptr != T)
    {
        RecurveMediumOrder(T->lchild);
        cout << T->data << " ";
        RecurveMediumOrder(T->rchild);
    }
}

void MediumOrder(BiTree T)
{
    stack<BiTree> s;
    BiTree p=T;
    while(p != nullptr || !s.empty())
    {
        while(p != nullptr)
        {
            s.push(p);
            p = p->lchild;
        }
        if (!s.empty()){
            p = s.top();
            s.pop();
            // cout << p->data;
            p = p->rchild;
        }
    }
}
void RecurvePostOrder(BiTree T)
{
    if (nullptr != T)
    {
        RecurvePostOrder(T->lchild);
        RecurvePostOrder(T->rchild);
        cout << T->data << " ";
    }
    
}

void PostOrder(BiTree T)
{
    stack<BiTree> s;
    BiTree p=T, r=nullptr;
    while (p != nullptr || !s.empty())
    {
        if (p)
        {
            s.push(p);
            p = p->lchild;  // 走到最左边
        }
        else
        {
            p = s.top();
            if (p->rchild != nullptr && p->rchild != r)
            {
                p = p->rchild;  //向右
                s.push(p);
                p = p->lchild; // 走到以右节点为根节点的 最左边
            }
            else
            {
                p = s.top();
                s.pop();
                cout << p->data << " ";
                r = p;
                p = nullptr;
            }
        }//else
    }//while
    
}

// // 判断两个二叉树是否相等
// bool isEqual(BiTree T1, BiTree T2)
// {
//     if (T1 == nullptr && T2 == nullptr)
//     {
//         return 1;
//     }
//     if (T1 == nullptr || T2 == nullptr)
//     {
//         return 0;
//     }
//     if (T1->data == T2->data)
//         // 左右子树不可旋转
//         return isEqual(T1->lchild, T2->lchild) && 
//             isEqual(T1->rchild, T2->rchild);
//         // 左右子树可旋转
//         // return isEqual(T1->lchild, T2->lchild) && 
//         //     isEqual(T1->rchild, T2->rchild) || isEqual(T1->lchild, T2->rchild) && 
//         //     isEqual(T1->rchild, T2->lchild)
//     else return 0;
// }

// int get_tree_height(BiTree T)
// {
//     int left, right;
//     if (T == nullptr)
//         return -1; // !
//     else
//     {
//         left = get_tree_height(T->lchild)+1;
//         right = get_tree_height(T->rchild)+1;
//     }
//     return (left>right)?left:right;
// }

// // 计算一个二叉树的最大距离
// struct RESULT
// {
//     int MaxDepth;
//     int MaxDistance;
// };

// RESULT get_maximum_dis(BiTree T)
// {
//     if (T == nullptr)
//     {
//         RESULT empty = {-1, 0};
//         return empty;
//     }
//     RESULT lrt = get_maximum_dis(T->lchild);
//     RESULT rrt = get_maximum_dis(T->rchild);
//     RESULT result;
//     result.MaxDepth = max(lrt.MaxDepth, rrt.MaxDepth)+1;
//     result.MaxDistance = max(max(lrt.MaxDistance, rrt.MaxDistance), 
//                                             lrt.MaxDepth+rrt.MaxDepth+2);
//     return result;
// }

// // 路径上所有节点之和等于给定值。不要求必须从根节点经过。   
// // 存在疑问！！！
// void print_buffer(vector<int> buffer, int start, int end)
// {
//     for (int i = start; i <= end; ++i)
//     {
//         cout << buffer[i] << " ";
//     }
//     cout << endl;
// }

// void find_sum(BiTree T, int sum, vector<int> buffer, int level)
// {
//     if (T == nullptr)
//         return;
//     int tmp = sum;
//     // 可能抛出 异常
//     // int data = atoi(T->data.c_str());
//     buffer.push_back(T->data);
//     for (int i = level; i >=0; --i)
//     {
//         tmp -= buffer[i];
//         if (tmp == 0)
//             print_buffer(buffer, i, level);
//     }
//     find_sum(T->lchild, sum, buffer, level+1);
//     buffer.pop_back();
//     level -= 1;
//     find_sum(T->rchild, sum, buffer, level+1);
// }

// //由遍历序列构造二叉树（前+中）
// BiTree construct_tree(int* start_preorder, int* end_preorder, int* start_inorder, int* end_inorder)
// {
//     int root_value = start_preorder[0];
//     BiTree root = NewNode(root_value);
//     if (start_preorder == end_preorder)
//     {
//         // try
//         // {
//         //     if (start_inorder == end_inorder && *start_preorder == *start_inorder)
//         //         return root;
//         //     else
//         //         throw text_exception("invalid input.\n");
//         // }
//         // catch (std::exception& ex) {
//         //     cout << root_value << " ";
//         //     std::cout << ex.what(); // custom text
//         // }
//         if (start_inorder == end_inorder && *start_preorder == *start_inorder)
//             return root;
//         else
//             throw exception();
//     }

//     int* root_inorder = start_inorder;
//     while (*root_inorder != root_value && root_inorder <= end_inorder)
//         ++root_inorder;

//     if (*root_inorder != root_value)
//         throw exception(); // 中序遍历中不存在root_value
    
//     int left_length = root_inorder - start_inorder;
//     int* left_end_preorder = start_preorder + left_length;
//     if (left_length > 0)
//         root->lchild = construct_tree(start_preorder+1, left_end_preorder, 
//                             start_inorder, root_inorder-1);
//     if (end_preorder-start_preorder > left_length)
//         root->rchild = construct_tree(left_end_preorder+1, end_preorder,
//                             root_inorder+1, end_inorder);
//     return root;
// }

// BiTree construct_with_pre_in(int* preorder, int* inorder, int length)
// {
//     if (preorder == nullptr || inorder == nullptr || length <= 0)
//         return nullptr;
//     return construct_tree(preorder, preorder+length-1, inorder, inorder+length-1);
// }

// // 判断一棵二叉树是否为二叉排序树

// int is_BST(BiTree T)
// {
//     int b1, b2;
//     if (T==nullptr)
//         return 1;
//     b1 = is_BST(T->lchild);
//     if (b1 == 0 || prev1 >= T->data)
//         return 0;
//     prev1 = T->data;
//     b2 = is_BST(T->rchild);
//     return b2;
// }

// //判断一棵树是不是二叉平衡树
// int max_depth(BiTree T)
// {
//     if (T == nullptr)
//         return 0;
//     return 1+max(max_depth(T->lchild), max_depth(T->rchild));
// }

// int min_depth(BiTree T)
// {
//     if (T == nullptr)
//         return 0;
//     return 1+min(min_depth(T->lchild), min_depth(T->rchild));
// }
// bool is_balanced(BiTree T)
// {
//     return (max_depth(T) - min_depth(T) <= 1);
// }

// int main()
// {
//     BiTree root;
//     // char s[20] = "A(B(D,),C(E,F(,H)))";
//     // char s[20] = "5(4(3,),9(6,12(,15)))";
    
//     root = Create_BiTree();
//     // cout << "height: " << get_tree_height(root) << endl;
//     // cout << "distance: " << get_maximum_dis(root).MaxDistance << endl;
//     cout << "is_BST: " << is_BST(root) << endl;
//     cout << "is_balanced: "<< is_balanced(root) << endl;
    
//     // vector<int> buffer;
//     // find_sum(root, 5, buffer, 0);
    
//     // construct tree test
//     // int preorder[] = {1,2,4,7,3,5,6,8};
//     // int inorder[] = {4,7,2,1,5,3,8,6};
//     // int *p, *q;
//     // p = preorder;
//     // q = inorder;
//     // root = construct_with_pre_in(p, q, 8);

//     cout << "PreOrder: ";
//     RecurveMediumOrder(root);
//     // cout << endl;
//     // cout << "RecurvePostOrder: ";
//     // RecurvePostOrder(root);
//     // cout << endl;

//     return 0;
// }

/*
命令行执行：
cd "/home/hadoop/VSProjects/exercise_cpp/" && g++ text_exception.cpp binary_tree.cpp
 -std=c++11 -o binary_tree && "/home/hadoop/VSProjects/exercise_cpp/"binary_tree
*/

