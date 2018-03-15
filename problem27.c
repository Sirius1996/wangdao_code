//北航2017机试第三题：二叉树的层次遍历 
// 1.用什么数据结构存放二叉树数据 
// 2.判断任意两个结点是否同辈
// 3同辈则输出共同祖先以及所在层，不同辈则从大往小输出结点值并输出其相差的辈数

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    struct Node *lchild,*rchild;
    int depth;
    int seq;
    char name[20];

}Node;

Node Tree[100];

int getSeq(char* name,int nodeNum)          //查找在树中的序号
{
    for(int i=0;i<nodeNum;i++)
        if(strcmp(name,Tree[i].name)==0)
            return i+1;
    return nodeNum+1;                       //查找失败
}

int main()
{
    int lineNum;
    scanf("%d",&lineNum);
    Node* T=NULL;

    for(int a=0;a<100;a++)                  //初始化树
        Tree[a].lchild=Tree[a].rchild=NULL;

    int arrCount=0,arrPtr=0,eleCount=0;
    int mul=2,inDepth=1;

    for(int a=0;a<lineNum*3;a++)            //将树放进队列
    {
        char nothing[20];
        T=&Tree[arrCount];
        if(a==0||(a>0&&a%3!=0))
        {
            scanf("%s",Tree[eleCount].name);
            Tree[eleCount].seq=eleCount+1;
            if(eleCount+1>=mul)
            {
                mul=mul*2;
                inDepth++;
            }
            Tree[eleCount].depth=inDepth;
            eleCount++;
            arrPtr++;
        }
        else
            scanf("%s",nothing);
        if(arrPtr==2)
        {
            T->lchild=&Tree[eleCount-2];
            T->rchild=&Tree[eleCount-1];
            arrPtr=0;
            arrCount++;
        }
    }
    //构建部分完成

    char seaName1[20],seaName2[20];
    scanf("%s",seaName1);
    scanf("%s",seaName2);
    int getSeq1=getSeq(seaName1,lineNum*2+1);
    int getSeq2=getSeq(seaName2,lineNum*2+1);
    int diff;
    Tree[getSeq1-1].depth>Tree[getSeq2-1].depth?(diff=(Tree[getSeq1-1].depth-Tree[getSeq2-1].depth)):(diff=Tree[getSeq2-1].depth-Tree[getSeq1-1].depth);//求高度差


    // printf("序号分别为：%d,%d\n",getSeq1,getSeq2);
    // printf("深度分别为：%d,%d\n",Tree[getSeq1-1].depth,Tree[getSeq2-1].depth);
    if(Tree[getSeq1-1].depth==Tree[getSeq2-1].depth)
    {
        while(getSeq1!=getSeq2)
        {
            // while(Tree[getSeq1].depth!=Tree[getSeq2].depth)
            // {
            //     if(Tree[getSeq1].depth<Tree[getSeq2].depth)
            //         getSeq2=getSeq2/2;
            //     else
            //         getSeq1=getSeq1/2;
            // }
            //上面注释掉的这一部分代码可以用来求不同层次上的公共祖先结点
            getSeq1=getSeq1/2;
            getSeq2=getSeq2/2;
        }
    }
    
    if(diff==0)
        printf("%s %d",Tree[getSeq1-1].name,Tree[getSeq1-1].depth);
    else
    {
        if(Tree[getSeq1-1].depth>Tree[getSeq2-1].depth)
            printf("%s %s %d\n",Tree[getSeq2-1].name,Tree[getSeq1-1].name,diff);
        else
            printf("%s %s %d\n",Tree[getSeq1-1].name,Tree[getSeq2-1].name,diff);
    }

    return 0;
}