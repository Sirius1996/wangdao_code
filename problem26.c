//北航17年机试第二题
//输入两行语法正确的C语言语句，第一行是定义变量，第二行是基本C语言表达式，输出第二行中没有在第一行被定义的变量名，如果是数组和指针，只输出数组名或指针名 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char dict[1000][100]={'\0'};
    char inputStr[1000]={'\0'};
    char tempChar[100]={'\0'};
    char temp;
    int mark1=0,mark2=0;
    int i;                          //用来计数
    while(scanf("%c",&temp)!='\n')
    {
        if(temp=='\n')
            break;
        inputStr[i]=temp;
        i++;
    }
                    
    for(i=0;inputStr[i]!='\n';i++)  //存入字典
    {
        while((inputStr[i]>='a'&&inputStr[i]<='z')||(inputStr[i]>='A'&&inputStr[i]<='Z')||inputStr[i]=='_'||(inputStr[i]>='0'&&inputStr[i]<='9'))
        {
            dict[mark1][mark2]=inputStr[i];
            mark2++;
            i++;
        }
        if(inputStr[i]==';')
            break;
        mark1++;
        mark2=0;
    }

    // for(int a=0;a<=mark1;a++)
    //     printf("%s\n",dict[a]);

    // printf("%d\n",i);

    for(int a=0;a<=i;a++)
        inputStr[a]='\0';
    i=0;
    while(scanf("%c",&temp)!='\n')
    {
        inputStr[i]=temp;
        if(temp=='\n')
            break;
        i++;
    }

    for(i=0;inputStr[i]!='\n';i++)
    {
        int a=0,judge=0;    //judge判断位
        while((inputStr[i]>='a'&&inputStr[i]<='z')||(inputStr[i]>='A'&&inputStr[i]<='Z')||inputStr[i]=='_'||(inputStr[i]>='0'&&inputStr[i]<='9'&&a!=0))
        {
            tempChar[a]=inputStr[i];
            a++;
            i++;
        }
        for(int b=0;b<=mark1;b++)
            if(strcmp(tempChar,dict[b])==0)
                judge=1;
        if(judge==0)
            printf("%s",tempChar);
        for(int c=0;c<=a;c++)
            tempChar[c]='\0';
    }
    return 0;
}