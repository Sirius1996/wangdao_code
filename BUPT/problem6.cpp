//北邮网研2014 ProblemA
#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n>0)
    {
        int a,b,temp,above=1,below=1;
        cin>>a>>b;
        if(a>b)
        {
            temp=a;
            a=b;
            b=temp;
        }
        while(a!=b)
        {
            above=above*2;
            a++;
        }
        above++;
        while(a>0)
        {
            below=below*2;
            a--;
        }
        cout<<above<<"/"<<below<<endl;
        n--;
    }
    return 0;
}