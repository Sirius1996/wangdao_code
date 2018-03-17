//北邮2016年计算机机试题目一

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector< vector<int> > inputNum;
    vector<int> outArr;
    int test;
    cin>>test;

    while(test>0)
    {
        int num;
        int ele;
        vector<int> tempArr;
        cin>>num;
        for(int i=0;i<num;i++)
        {
            cin>>ele;
            tempArr.push_back(ele);
        }
        inputNum.push_back(tempArr);
        tempArr.clear();
        test--;
    }

    for(int a=0;a<inputNum.size();a++)
    {
        int count;
        for(int b=0;b<inputNum[a].size();b++)
        {
            count=0;
            for(int i=0;i<inputNum[a].size();i++)
                for(int j=0;j<inputNum[a].size();j++)
                    for(int k=0;k<inputNum[a].size();k++)
                        if(inputNum[a][i]+inputNum[a][j]==inputNum[a][k])
                            count++;
            
        }
        outArr.push_back(count);
    }

    for(int i=0;i<outArr.size();i++)
        cout<<outArr[i]<<endl;
    return 0;
}