#include<iostream>

using namespace std;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int lcm(int a,int b)//最小公倍数：两数之积除以最大公约数
{
    int temp=gcd(a,b);
    return a*b/temp;
}

int main()
{
    int a,b;
    cin>>a;
    cin>>b;
    int res=lcm(a,b);
    cout<<res<<endl;
    return 0;
}