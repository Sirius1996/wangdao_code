//2013 Problem B
#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string time1,time2;
        int h1,h2,m1,m2,res;
        cin>>time1>>time2;
        if(time1[1]==':')
        {
            h1=time1[0]-'0';
            m1=(time1[2]-'0')*10+time1[3]-'0';
        }
        else
        {
            h1=(time1[0]-'0')*10+time1[1]-'0';
            m1=(time1[3]-'0')*10+time1[4]-'0';
        }
        if(time2[1]==':')
        {
            h2=time2[0]-'0';
            m2=(time2[2]-'0')*10+time2[3]-'0';
        }
        else
        {
            h2=(time2[0]-'0')*10+time2[1]-'0';
            m2=(time2[3]-'0')*10+time2[4]-'0';
        }
        //计算差值
        if(h1-h2>0)
            res=(h1-h2)*60+m1-m2;
        else
            res=(h2-h1)*60+m2-m1;
        cout<<res<<endl;
    }
    return 0;
}