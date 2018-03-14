//n个点，m条无向边，每条边都有长度d和花费p，给起点s和终点t
//要求输出起点到终点的最短距离及其花费，如果最短距离有多条路线，则输出花费最少的

#include<iostream>
#include<vector>

using namespace std;

typedef struct line
{
    int cost;
    int len;
}line;

int main()
{
    int m,n;                    //n行，m个元素
    int s,t;
    vector< vector<line> > arr;
    vector<line> tempArr;
    line tempData;

    cin>>m;
    cin>>n;

    for(int i=0;i<m;i++)        //预处理
    {
        for(int j=0;j<m;j++)
        {
            tempData.cost=-1;
            tempData.len=-1;
            tempArr.push_back(tempData);
        }
        arr.push_back(tempArr);
        arr[i][i].len=0;
    }
    while(n>0)                  //输入
    {
        int a,b,d,p;

        cin>>a;
        cin>>b;
        cin>>d;
        cin>>p;
        
        arr[a-1][b-1].len=d;
        arr[a-1][b-1].cost=p;
        n--;
    }
    cin>>s;
    cin>>t;

    //求s到t之间最短路径
    vector<int> seq;
    int judgeLen=65535;
    for(int a=0;a<m;a++)
        seq.push_back(-1);
    
    int mark1=0,mark2=0;
    //int sum=0;
    int tag1,tag2;
    while(seq.size()<m)
    {

        judgeLen=65535;
        for(int a=0;a<m;a++)
            if(arr[mark1][a].len==-1||arr[mark1][a].len+arr[tag1][tag2].len<arr[tag1][a].len)
                arr[tag1][a].len=arr[tag1][tag2].len+arr[mark1][a].len;
        
        for(int a=0;a<m;a++)
            if(arr[mark1][a].len!=-1&&arr[mark1][a].len<judgeLen)//找最小的一条边
            {
                judgeLen=arr[mark1][a].len;
                tag1=mark1,tag2=a;
            }
        if(find(seq.begin(),seq.end(),tag1)==seq.end())
            seq.push_back(tag1);
        if(find(seq.begin(),seq.end(),tag2)==seq.end())
            seq.push_back(tag2);
        arr[tag1][tag2].len=judgeLen;
        mark1=tag2;
    }

    cout<<arr[1][t].len-arr[1][s].len<<endl;

    return 0;
}