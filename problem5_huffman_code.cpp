#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int NodeNum;
    int times;
    queue<int> Q;
    scanf("%d",&NodeNum);
    times=NodeNum;
    int tree[1000]={0};
    int res=0;
    for(int i=0;i<NodeNum;i++)
        scanf("%d",&tree[i]);

    for(int i=0;i<NodeNum;i++)
        cout<<tree[i]<<" ";
    cout<<endl;
    while(times>1)
    {
        int judge=101;
        int pos=0;
        for(int i=0;i<NodeNum;i++)
        {
            if(judge>=tree[i]&&tree[i]>0)
            {
                judge=tree[i];
                pos=i;
            }
        }
        int a=judge;
        Q.push(judge);
        tree[pos]=0;
        cout<<judge<<endl;

        judge=101;
        for(int i=0;i<NodeNum;i++)
        {
            if(judge>=tree[i]&&tree[i]>0)
            {
                judge=tree[i];
                pos=i;
            }
        }
        int b=judge;
        Q.push(judge);
        tree[pos]=0;
        cout<<judge<<endl;
        res=a+b+res;
        tree[pos]=res;
        cout<<"res now is: "<<res<<endl;

        times--;
    }
    
    // while(Q.size()>0)
    // {
    //     int a=Q.front();
    //     Q.pop();
    //     int b=Q.front();
    //     Q.pop();
    //     res=res+a+b;
    //     Q.push(res);
    //     cout<<"res now is:"<<res<<endl;
    // }
    printf("The result is : %d\n",res);
    return 0;
}