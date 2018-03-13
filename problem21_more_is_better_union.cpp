//利用并查集来处理这类问题

#include<iostream>
#include<vector>


using namespace std;

int resTree[10000]={-1};
int sum[10000]={1};

int findRoot(int x)
{
    if(resTree[x]==-1)
        return x;
    else
        return findRoot(resTree[x]);
}

int main()
{
    //vector<int> resCol;
    int num;
    cin>>num;
    while(num!=0)
    {
        for(int k=0;k<10000;k++)
        {
            resTree[k]=-1;
            sum[k]=1;
        }
        for(int k=0;k<num;k++)
        {
            int m,n;
            cin>>m;
            cin>>n;
            m=findRoot(m);      //找最顶端度祖先节点
            n=findRoot(n);
            if(m!=n)
            {
                resTree[m]=n;
                sum[n]=sum[m]+sum[n];       //合并之后，成为子树的树根节点上保存的该元素的个数度数字累积加到合并后新的树根
            }
        }
        //for(int i=0;i<10000;i++)
            //if(find(resCol.begin(), resCol.end(),resTree[i])==resCol.end())
            //if(resTree[i]!=-1)
                //resCol.push_back(resTree[i]);
        //cout<<resCol.size()<<endl;
        for(int i=0;i<10000;i++)
            if(resTree[i]!=-1)
                sum[i]++;
        int judge=0;
        for(int i=0;i<10000;i++)
            if(sum[i]>judge)
                judge=sum[i];
        cout<<judge<<endl;
        cin>>num;
    }
    return 0;
}