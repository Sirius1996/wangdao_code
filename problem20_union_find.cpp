//并查集问题

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector< vector<int> > col;
    int m,n;
    cin>>m;
    cin>>n;
    while(n!=0)
    {
        for(int i=0;i<n;i++)
        {
            int dist1,dist2;
            vector<int> tempDist;
            cin>>dist1;
            cin>>dist2;

            for(int k=0;k<col.size()||col.size()==0;k++)
            {
                //cout<<"进来了"<<endl;
                if(col.size()==0)
                {
                    tempDist.push_back(dist1);
                    tempDist.push_back(dist2);
                    col.push_back(tempDist);
                    //cout<<"新建"<<endl;
                }
                if(find(col[i].begin(),col[i].end(),dist1)==col[i].end()&&find(col[i].begin(),col[i].end(),dist2)==col[i].end())
                {
                    tempDist.push_back(dist1);
                    tempDist.push_back(dist2);
                    col.push_back(tempDist);
                }
                else if(find(col[i].begin(),col[i].end(),dist1)==col[i].end())
                    col[i].push_back(dist1);
                else if(find(col[i].begin(),col[i].end(),dist2)==col[i].end())
                    col[i].push_back(dist2);
                cout<<"第"<<i<<"个元素规模："<<col[i].size()<<",分别为"<<endl;
                for(int j=0;j!=col[i].size();j++)
                    cout<<col[i][j]<<" ";
                cout<<endl;
                
            }
            //cout<<"第"<<i<<"趟"<<endl;
        }
        cout<<col.size()-1<<endl;
        cin>>m;
        cin>>n;
    }
    return 0;
}