#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int size;
    cin>>size;
    vector<int> num;
    for(int i=0;i<=size;i++)
    {
        cin>>size;
        num.push_back(size);
    }
    for(auto ptr=num.begin();ptr!=num.end();ptr++)
        cout<<*ptr<<endl;
    for(int i=0;i<size;i++)
        for(int j=i;j<size;j++)
            if(num[i]>num[j])
            {
                int temp=num[i];
                num[i]=num[j];
                num[j]=temp;
            }

    for(auto ptr=num.begin();ptr!=num.end();ptr++)
        cout<<*ptr<<endl;
    return 0;
}