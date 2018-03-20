//2015北邮计算机机试第三题
#include<iostream>
#include<vector>

using namespace std;

int findCube(vector< vector<int> > arr)            //找出最大正方形,传形参
{

    int count=0,flag=0,len,tag;
    for(int a=0;a<arr.size();a++)
        for(int b=0;b<arr[a].size();b++)
        {
            if(arr[a][b]==1)
            {
                flag=1;
                if(flag==1)
                    for(len=1;(len+a)<arr.size()&&(len+b)<arr.size();len++)
                        for(int i=a;i<a+len;i++)
                            for(int j=b;j<b+len;j++)
                                flag=flag*arr[i][j];
                if(flag==0)
                    tag=len-1;
                else
                    tag=len;
                if(count<tag)
                    count=tag;
            }
        }
    return count;
}

int main()
{
    int line,times;
    vector< vector<int> > arr1,arr2;
    cin>>line;
    times=line;
    while(times--)
    {
        int num;
        vector<int> tempArr;
        for(int a=0;a<line;a++)
        {
            cin>>num;
            tempArr.push_back(num);
        }
        arr1.push_back(tempArr);
        tempArr.clear();
    }
    times=line;
    while(times--)
    {
        int num;
        vector<int> tempArr;
        for(int a=0;a<line;a++)
        {
            cin>>num;
            tempArr.push_back(num);
        }
        arr2.push_back(tempArr);
        tempArr.clear();
    }
    for(int a=0;a<line;a++) 
        for(int b=0;b<line;b++)                        //两图重叠
            (arr1[a][b]==arr2[a][b])?(arr1[a][b]=1):arr1[a][b]=0;
    cout<<findCube(arr1)<<endl;

    return 0;
}