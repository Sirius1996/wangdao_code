#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int num;
    int a;
    cin>>num;
    cin>>a;
    vector<int> res;
    int k=num;                      //k为各素数幂次中最小的那个。
    for(int i=0;i<=num;i++)
        res.push_back(0);
    res[0]=1;
    res[1]=1;
    for(int i=3;i<=num;i++)
    {
        if(res[i]==0)
        {
            for(int j=2;j<i;j++)
                if(i%j==0)
                    res[i]=1;
            for(int temp=2;i*temp<num;temp++)
                res[i*temp]=1;
        }
    }
    for(int i=2;i<=num;i++)
        if(res[i]==0&&num%i==0)
            res[i]=num%i;

    int count=0;
    for(int i=2;i<=num;i++)
        if(res[i]!=0&&res[i]!=1)
        {
            int temp=a;

            for(int j=0;temp<=num;j++)
            {
                temp=temp*temp;
                count++;
            }
            cout<<"count:"<<count<<endl;
            if(count<k)
                k=count;
        }
    if(count<=1)
        k=1;
    cout<<k<<endl;

    return 0;
}