#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int m,n;
    cin>>m;
    cin>>n;
    while(m!=0&&m!=0)
    {
        vector< vector<int> > arr;
        //vector< vector<int> > len;
        for(int a=0;a<m;a++)
        {
            vector<int> temp;
            for(int b=0;b<m;b++)  
                temp.push_back(65535);
            arr.push_back(temp);
            arr[a][a]=0;
        }
        for(int k=0;k<n;k++)
        {
            int inA,inB,inC;
            cin>>inA;
            cin>>inB;
            cin>>inC;
            arr[inA-1][inB-1]=inC;
            arr[inB-1][inA-1]=inC;
        }
        //Floyd算法
        for(int c=0;c<m;c++)
            for(int a=0;a<m;a++)
                for(int b=0;b<m;b++)
                {
                    if(arr[a][c]+arr[c][b]<arr[a][b]||arr[a][b]==65535)
                        arr[a][b]=arr[a][c]+arr[c][b];
                }

        cout<<arr[0][m-1]<<endl;
        cin>>m;
        cin>>n;
    }
    return 0;
}