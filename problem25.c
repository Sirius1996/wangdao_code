//2017北航机试第一题

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int inputNum[100];
    int i=0;
    char judge;
    while(scanf("%c",&judge)!='\n')
    {
        if(judge=='\n')
            break;
        if(judge!=' ')
        {
            inputNum[i]=judge-'0';
            i++; 
        }

    }

    for(int a=0;a<i;a++)
        for(int b=0;b<i;b++)
            if(inputNum[a]<inputNum[b])
            {
                int temp=inputNum[a];
                inputNum[a]=inputNum[b];
                inputNum[b]=temp;
            }
    if(i%2==0)
        printf("%d ",inputNum[i/2-1]);
    printf("%d\n",inputNum[i/2]);
    return 0;
}
