//2015 Problem A
#include<iostream>

using namespace std;

bool isPrime(int inNum)
{
    int count=0;
    for(int a=2;a<inNum;a++)
        if(inNum%a==0)
            count++;
    if(count==0)
        return true;
    return false;
}

void prime(int num)
{
    for(int i=2;i<num;i++)
        if(isPrime(i))
            cout<<i<<" ";
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int num;
        cin>>num;
        prime(num);
    }
    return 0;
}