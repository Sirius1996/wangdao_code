// 二分求幂：求A^B的最后三位表示的整数。


#include<iostream>

using namespace std;

int power(int a,int b)
{
    int ans=1;
    while(b!=0)
    {
        if(b%2==1)
            ans=ans*a;
        b=b/2;
        a=a*a;
    }
    return ans;
}

int main()
{
    int a,b;
    cin>>a;
    cin>>b;
    int res=power(a,b);
    cout<<res<<endl;
    return 0;
}