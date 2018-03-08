#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int num;
    cin>>num;
    vector<int> res;
    int temp=2;
    while(num!=1)
    {
        while(num%temp==0)
        {
            res.push_back(temp);
            num=num/temp;
        }
        temp++;
    }
    for(auto ptr=res.begin();ptr!=res.end();ptr++)
        cout<<*ptr<<endl;
    return 0;
}