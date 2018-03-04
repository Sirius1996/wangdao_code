#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;

typedef struct Data{
    int begin;
    int end;
    bool operator < (const Data& inputData) const
    {
        return end<inputData.end;
    }
}Data;

int main()
{
    int inputSize;
    int judge=0,count=0;
    cin>>inputSize;
    vector<Data> list;
    Data inputData;
    for(int i=0;i<inputSize;i++)
    {
        cin>>inputData.begin;
        cin>>inputData.end;
        list.push_back(inputData);
    }
    sort(list.begin(),list.end());
    for(int i=0;i<inputSize;i++)
    {
        if(list[i].end>judge&&list[i].begin>=judge)
        {
            judge=list[i].end;
            count++;
        }
    }
    // for(int i=0;i<inputSize;i++)
    // {
    //     cout<<list[i].begin<<" ";
    //     cout<<list[i].end<<endl;
    // }
    cout<<count;
    return 0;
}