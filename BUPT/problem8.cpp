//2014北邮网研机试Problem D：网络传输
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int t;
    vector< vector<int> > arr;
    vector<int> target;
    cin>>t;
    while(t--)
    {
        int n,m,k,temp1,temp2;          //结点数，边数，目标结点数
        cin>>n>>m>>k;
        for(temp1=0;temp1<n;temp1++)
        {
            vector<int> intArr;
            for(temp2=0;temp2<n;temp2++)
                intArr.push_back(-1);
            arr.push_back(intArr);
        }
        while(m--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            arr[u-1][v-1]=w;
            arr[v-1][u-1]=w;
        }
        while(k--)
        {
            int size;
            cin>>size;
            target.push_back(size);
        }
        
    }
}