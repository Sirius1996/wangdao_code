#include<iostream>
#include<string>
//#include<cstring>

using namespace std;

int main()
{
    int a,b;
    string num;
    long res=0;
    string outputNum;
    cin>>a;
    cin>>num;
    cin>>b;
    for(int i=0;i<num.size();i++)
    {
        if(num[i]>='0'&&num[i]<='9')
            res=res*a+num[i]-'0';
        else if(num[i]>='a'&&num[i]<='z')
            res=res*a+num[i]-'a'+10;
        else if(num[i]>='A'&&num[i]<='Z')
            res=res*a+num[i]-'A'+10;
    }
    while(res!=0)
    {
        if(res%b>=10)
            outputNum.push_back(res%b+'A'-10);
        else
            outputNum.push_back(res%b+'0');
        res=res/b;
    }
    //strrev(outputNum);
    //outputNum.reserve();
    for(int i=outputNum.size();i>=0;i--)
        cout<<outputNum[i];
    cout<<endl;
    return 0;
}