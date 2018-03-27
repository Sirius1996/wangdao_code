//2014北邮网研机试题B：最小堆
#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node* lchild,*rchild;
};

typedef struct Node Node;

bool judge(Node* leaf)
{
    if(leaf->lchild!=NULL)
    {
        if((leaf->lchild->data)<(leaf->data))
            return false;
        else if(judge(leaf->lchild)==false)
            return false;
    }
    else if(leaf->rchild!=NULL)
    {
        if((leaf->rchild->data)<(leaf->data))
            return false;
        else if(judge(leaf->rchild)==false)
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,tempN;
        vector<Node> tree;
        cin>>n;
        tempN=n;
        while(tempN--)
        {
            int num;
            cin>>num;
            Node tempNode;
            tempNode.lchild=NULL;
            tempNode.rchild=NULL;
            tempNode.data=num;
            tree.push_back(tempNode);
        }
        tempN=n-1;
        while(tempN--)          //建树
        {
            int u,v;
            cin>>u>>v;
            if(v==(2*u))
                tree[u].lchild=&tree[v];
            else
                tree[u].rchild=&tree[v];
        }
        Node* ptr=&tree[1];     //注意这里从1开始编号
        bool judgeTag=judge(ptr);
        if(judgeTag)
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }
    return 0;
}