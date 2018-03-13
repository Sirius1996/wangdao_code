#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector< vector<int> > resCol;
    int num,res=0;
    cin>>num;
    while(num!=0)
    {
        for(int i=0;i<num;i++)
        {
            vector<int> tempCol;
            int f1,f2;
            cin>>f1;
            cin>>f2;
            if(resCol.size()==0)
            {
                tempCol.push_back(f1);
                tempCol.push_back(f2);
                resCol.push_back(tempCol);
            }
            for(int j=0;j<resCol.size();j++)
            {
                if(find(resCol[j].begin(),resCol[j].end(),f1)==resCol[i].end()&&find(resCol[j].begin(),resCol[j].end(),f2)==resCol[j].end())
                {
                    tempCol.push_back(f1);
                    tempCol.push_back(f2);
                    resCol.push_back(tempCol);  
                }
                else if(find(resCol[j].begin(),resCol[j].end(),f1)==resCol[i].end())
                    resCol[j].push_back(f1);
                else if(find(resCol[j].begin(),resCol[j].end(),f2)==resCol[i].end())
                    resCol[j].push_back(f2);
            }
        }
        cin>>num;
    }
    for(int i=0;i<resCol.size();i++)
        if(resCol[i].size()>res)
            res=resCol[i].size();
    cout<<res<<endl;
}