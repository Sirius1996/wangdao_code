#include<iostream>
#include<string>

using namespace std;

struct Node
{
    Node * lchild;
    Node * rchild;
    char c;
}Tree[50];
int loc;                        //静态数组中已经分配的结点数

Node * creat()
{
    Tree[loc].lchild=Tree[loc].rchild=NULL;
    return &Tree[loc++];
}
string str1,str2;
void postOrder(Node *T)//后序遍历
{
    if(T->lchild!=NULL)
        postOrder(T->lchild);
    if(T->rchild!=NULL)
        postOrder(T->rchild);
    cout<<T->c;
}
Node *build(int s1,int e1,int s2,int e2)
{
    Node* ret=creat();
    ret->c=str1[s1];
    int rootIdx;
    for(int i=s2;i<=e2;i++)
    {
        if(str2[i]==str1[s1])   //查找该跟结点字符在中序遍历中的位置
        {
            rootIdx=i;
            break;
        }
    }
    if(rootIdx!=s2)             //左子树不为空
        ret->lchild=build(s1+1,s1+(rootIdx-s2),s2,rootIdx);
    if(rootIdx!=e2)             //右子树不为空
        ret->rchild=build(s1+(rootIdx-s2),e1,rootIdx+1,e2);
    return ret;
}


int main()
{
    loc=0;
    cin>>str1;
    cin>>str2;
    int L1=str1.size();
    int L2=str2.size();
    Node *T=build(0,L1-1,0,L2-1);
    postOrder(T);
    cout<<endl;

    return 0;

}