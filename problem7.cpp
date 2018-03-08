#include<iostream>
#include<string>

using namespace std;

struct Node
{
    Node * lchild;
    Node * rchild;
    char c;
}Tree[50];
int loc;    //静态数组中已经分配的结点数

Node * creat()
{
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}
char str1[30],str2[30];
void postOrder(Node *T)//后序遍历
{
    if(T->lchild!=NULL)
        postOrder(T->lchild);
    if(T->rchild!=NULL)
        postOrder(T->rchild);
    cout<<T->c;
}


int main()
{
    
}