#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int m,num1,num2;
    cin>>m;
    cin>>num1;
    cin>>num2;
    int sum=num1+num2;
    int res;
    int mul=1;
    while(sum!=0)
    {
        res=res+(sum%m)*mul;
        sum=sum/m;
        mul=mul*10;
    }
    cout<<res<<endl;
    return 0;
}