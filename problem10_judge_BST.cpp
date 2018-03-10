#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef struct Node
{
    Node* lchild;
    Node* rchild;
    int data;
}Ndoe;
//Node Tree[100];
int loc;
Node* creat(Node* Tree)
{
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}

//int size1,size2;
//vector<int> judge1,judge2;

Node* Insert(Node* T,int num)
{
    if(T==NULL)
    {
        T=creat(T);
        T->data=num;
        return T;
    }
    else if(num<T->data)
        T->lchild=Insert(T->lchild,num);
    else if(num>T->data)
        T->rchild=Insert(T->rchild,num);
    return T;
}

void PreOrder(Node* T,vector<int> judge)
{
    judge.push_back(T->data);
    if(T->lchild)
        PreOrder(T->lchild,judge);
    if(T->rchild)
        PreOrder(T->rchild,judge);
}

void InOrder(Node* T,vector<int> judge)
{
    if(T->lchild)
        InOrder(T,judge);
    judge.push_back(T->data);
    if(T->rchild)
        InOrder(T,judge);
}

int main()
{
    Node Tree[100];
    Node judgeTree[100];
    Node* T1=NULL,*T2=NULL;
    int judgeNum;
    vector<int> st1,st2,judge1,judge2;
    int judgeTag;                   //1为真

    cin>>judgeNum;
    char temp;
    cin>>temp;
    while(temp!='\0')
    {
        int inNum=temp-48;
        T1=Insert(Tree,inNum);
        cin>>temp;
    }
    PreOrder(T1,st1);
    InOrder(T1,st2);

    temp='1';
    cin>>temp;
    while(judgeNum>0)
    {
        judgeTag=1;
        while(temp!='\0')
        {
            int inNum=temp-48;
            T2=Insert(judgeTree,inNum);
            cin>>temp;
        }
        PreOrder(T2,judge1);
        InOrder(T2,judge2);
        for(int i=0;i<st1.size();i++)
            if(judge1[i]!=st1[i]||judge2[i]!=st2[i])
                judgeTag=0;
        
        if(judgeTag==0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
        judgeNum--;
    }

    return 0;
}