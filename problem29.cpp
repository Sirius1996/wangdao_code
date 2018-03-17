//北邮2016年计算机机试题目二

#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n>0)
    {
        string input;
        //string output;
        int count=0;
        cin>>input;
        for(int a=0;a<input.size();a++)
        {
            if(input[a]=='1')
                count++;
            else if(count==5)
            {
                for(int b=a;b<input.size()-1;b++)
                    input[b]=input[b+1];
                input[input.size()-1]='\0';
                count=0;
            }
            else
                count=0;
        }
        cout<<input<<endl;
        input.clear();
        n--;
    }
}