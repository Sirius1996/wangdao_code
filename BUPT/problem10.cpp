//2016 Problem D
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string opStr;
    string outStr;
    int opNum;
    cin>>opStr;
    cin>>opNum;
    for(int i=0;i<opStr.size();i++)
        outStr.push_back(opStr[i]);
    while(opNum--)
    {
        string op;
        cin>>op;
        if(op=="cut")
        {
            int start=op[4]-'0',end=op[6]-'0';
            outStr.clear();
            for(int i=start;i<=end;i++)
                outStr.push_back(opStr[i]);
            for(int i=end+1;i<opStr.size();i++)     //实现删除
            {
                opStr[i-end+start-1]=opStr[i];
                opStr[i]='\0';
            }
            cout<<opStr<<endl;
        }
        else if(op=="copy")
        {
            outStr.clear();
            int start=op[5]-'0',end=op[7]-'0';
            for(int i=start;i<=end;i++)
                outStr.push_back(opStr[i]);
            cout<<opStr<<endl;
        }
        else if(op=="paste")
        {
            int pos=op[6]-'0',a=0,b=0;
            string temp;
            for(int i=0;i<opStr.size()+outStr.size();i++)
            {
                if(i>pos&&i<=pos+outStr.size())
                {
                    temp.push_back(outStr[a]);
                    a++;
                }
                else
                {
                    temp.push_back(opStr[b]);
                    b++;
                }
            }
            opStr.clear();
            for(int i=0;i<temp.size();i++)
                opStr.push_back(temp[i]);
            cout<<opStr<<endl;
        }
    }
    return 0;
}