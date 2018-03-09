#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef struct Node
{
    Node* lchild;
    Node* rchild;
    int c;
}Node;
Node Tree[110];
int loc;

Node * creat()
{
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}

Node * Insert(Node *T,int num)
{
    if(T==NULL)
    {
        T=creat();                      //若根为空，建立树
        T->c=num;
        return T;
    }
    else if(num<T->c)
        T->lchild=Insert(T->lchild,num);
    else if(num>T->c)
        T->rchild=Insert(T->rchild,num);
    return T;
}

void PreOrder(Node *T)                 //前序遍历
{
    cout<<T->c;
    if(T->lchild)
        PreOrder(T->lchild);
    if(T->rchild)
        PreOrder(T->rchild);
}

void InOrder(Node *T)
{
    if(T->lchild)
        InOrder(T->lchild);
    cout<<T->c;
    if(T->rchild)
        InOrder(T->rchild);
}

void PostOrder(Node *T)
{
    if(T->lchild)
        PostOrder(T->lchild);
    if(T->rchild)
        PostOrder(T->rchild);
    cout<<T->c;
}




int main()
{
    int n;
    cin>>n;
    loc=0;
    Node *T=NULL;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        T=Insert(T,num);
    }
    PreOrder(T);
    cout<<endl;
    InOrder(T);
    cout<<endl;
    PostOrder(T);
    cout<<endl;

    return 0;
}