//北邮2016年计算机机试题目三
#include<iostream>

using namespace std;

int main()
{
    int inputNum;
    cin>>inputNum;
    while(inputNum>0)
    {
        int n,m,count=0;
        cin>>n>>m;
        for(int a=1;a<=n;a++)
            if(m%a==0&&m/a<=n)
                count++;
        cout<<count<<endl;
        count=0;

        inputNum--;
    }
}