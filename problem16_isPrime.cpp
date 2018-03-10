#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> range;
    int num;
    cin>>num;
    for(int i=0;i<=num;i++)
        range.push_back(0);
    range[0]=1;
    range[1]=1;
    for(int i=3;i<=num;i++)
    {
        if(range[i]==0)
        {
            for(int j=2;j<i;j++)
                if(i%j==0)
                    range[i]=1;
            for(int temp=2;i*temp<num;temp++)
                range[i*temp]=1;
        }
    }   
    for(int i=0;i<num;i++)
        if(range[i]==0&&i%10==1)
            cout<<i<<" ";
    cout<<endl;
    return 0;
}