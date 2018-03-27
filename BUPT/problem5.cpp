#include<iostream>
#include<vector>
#include<string>

using namespace std;

void delElem(int* arrPtr,int* delPtr,int seq)
{
    for(int i=1;i<100;i++)
    {
        if(arrPtr[i]==seq&&i>0)
            delElem(arrPtr,delPtr,i);
        arrPtr[i]=-1;
        delPtr[i]=1;
    }
}

int main()
{
    int t,n;    //t组数，n行数
    int addArr[100],killArr[100];
    for(int i=0;i<100;i++)
    {
        addArr[i]=-1;
        killArr[i]=-1;
    }
    addArr[0]=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        while(n>=0)
        {
            int addNum,killNum;
            string inputStr;
            getline(cin,inputStr);
            if(inputStr[0]=='F')
            {
                int i=inputStr[5]-'0';
                int j=inputStr[7]-'0';
                if(addArr[i]!=-1&&killArr[j]==-1)
                    addArr[j]=i;
                cout<<"Yes"<<endl;
            }
            else if(inputStr[0]=='Q')
            {
                cout<<inputStr[6]-'0'<<"  "<<addArr[inputStr[6]-'0']<<endl;
                if(addArr[inputStr[6]-'0']==-1)
                    cout<<"No"<<endl;
                else
                    cout<<"Yes"<<endl;
            }
            else if(inputStr[0]=='K')       //这里杀死进程时候要同时杀死子进程
            {
                int seq=inputStr[5]-'0';
                delElem(addArr,killArr,seq);
            }
            n--;
        }
    }
    return 0;
}