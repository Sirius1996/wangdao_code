#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int num;
    int vill[100][100]={-1};
    cin>>num;

    while(num!=0)
    {
        int sum=0,judge=100,count=num;
        vector<int> villCol;
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)
                vill[i][j]=-1;

        for(int k=0;k<num;k++)
        {
            int a,b,dist;
            cin>>a;
            cin>>b;
            cin>>dist;
            vill[a-1][b-1]=dist;
        }
        while(count>0)
        {
            int tag1,tag2;
            for(int i=0;i<num;i++)
            {
                for(int j=i+1;j<num;j++)
                {
                    if(vill[i][j]<judge&&vill[i][j]!=-1)
                    {
                        tag1=i;
                        tag2=j;
                        judge=vill[i][j];
                    }
                }
            }
            if(find(villCol.begin(),villCol.end(),tag1)==villCol.end()&&find(villCol.begin(),villCol.end(),tag2)==villCol.end())
            {
                villCol.push_back(tag1);
                villCol.push_back(tag2);
                count=count-2;
            }
            else if(find(villCol.begin(),villCol.end(),tag1)==villCol.end())
            {
                villCol.push_back(tag1);
                count--;
            }
            else if(find(villCol.begin(),villCol.end(),tag2)==villCol.end())
            {
                villCol.push_back(tag2);
                count--;
            }
            sum=sum+vill[tag1][tag2];
            vill[tag1][tag2]=-1;
            judge=100;
        }
        cout<<sum<<endl;
        villCol.clear();
        cin>>num;
    }
    return 0;
}