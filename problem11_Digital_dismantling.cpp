#include<iostream>

using namespace std;

int main()
{
    int num1,num2;
    cin>>num1;
    cin>>num2;
    int res=0;
    while(num1!=0)
    {
        int temp1=num1%10;
        int inNum2=num2;
        while(inNum2!=0)
        {
            int temp2=inNum2%10;
            res=res+temp1*temp2;
            inNum2=inNum2/10;
        }
        num1=num1/10;
    }
    cout<<res<<endl;
    return 0;
}