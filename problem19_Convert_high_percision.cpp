#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    vector<int> inNum;
    vector<int> stdNum;
    string res;
    string inputStr;
    int x,y;
    cin>>x;
    cin>>y;
    cin>>inputStr;
    int carry=0;//余数
    for(int i=0;i<inputStr.size();i++)
    {

        if(inputStr[i]>='0'&&inputStr[i]<='9')
            inNum.push_back(inputStr[i]-48);
        else if(inputStr[i]>='A'&&inputStr[i]<='Z')
            inNum.push_back(inputStr[i]-'A'+10);
    }


    //int bitRes=0;
    for(int i=0;i<inNum.size();i++) //把某进制转换成标准十进制
    {
        cout<<"进来了"<<endl;
        inNum[i]=inNum[i]*x;
        stdNum.push_back(inNum[i]%10+carry);
        carry=inNum[i]/10;
    }
    if(carry!=0)
        stdNum.push_back(carry);

    for(int i=0;i<stdNum.size();i++)
        cout<<stdNum[i]<<" ";

    carry=0;
    for(int i=0;i<stdNum.size();i++)
    {
        int temp;
        if(stdNum[i+1])
            temp=stdNum[i]+stdNum[i+1]+carry;
        else
            temp=stdNum[i]+carry;
        while(temp!=0)
        {
            res.push_back(temp%y);
            carry=temp%y;
            temp=temp/y;
        }
    }

    for(int i=res.size();i>0;i--)
        cout<<res[i]<<" ";
    cout<<endl;
    
    return 0;
    
}