//2013 Problem A
#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int num,max1=0,max2=0,temp;
        cin>>num;
        while(num--)
        {
            cin>>temp;
            if(temp>max2)
            {
                if(temp>max1)
                {
                    max2=max1;
                    max1=temp;
                }
                else
                    max2=temp;
            }
        }
        cout<<max1<<" "<<max2<<endl;
    }
    return 0;
}