/**
结点数目不超过200时可使用
时间复杂度O(n^3)，空间复杂度O(n^2)
当结点数过多时，程序可能会超时
**/
#include <stdio.h>
#include <stdlib.h>
#define infinity 65535
#define N 101

int Matrix[N][N];

void init(int edge)
{
    int i, j;
    for(i = 1; i <= edge; i++)
    {
        for(j = 1; j <= edge; j++)
        {
            if(i == j)
                Matrix[i][j] = 0;
            else
                Matrix[i][j]  =infinity;
        }
    }
}

void Floyed(int numN)
{
    //int i, j, k;
    for(int k = 1; k <= numN; k++)
    {
        for(int i = 1; i <= numN; i++)
        {
            for(int j = 1; j <= numN; j++)
            {
                if(Matrix[i][k] == infinity || Matrix[k][j] == infinity)
                    continue;
                if(Matrix[i][j] > Matrix[i][k]+Matrix[k][j] || Matrix[i][j] == infinity)
                    Matrix[i][j] = Matrix[i][k]+Matrix[k][j];
            }
        }
    }
    printf("%d\n", Matrix[1][numN]);
}

int main()
{
    int numN, numM;
    int a, b, c;
    while(scanf("%d %d", &numN, &numM) != EOF)
    {
        if(numN == 0 && numM == 0)
            break;
        
        init(numN);
        while((numM --) != 0)
        {
            scanf("%d %d %d", &a, &b, &c);
            Matrix[a][b] = Matrix[b][a] = c;
        }
        Floyed(numN);
    }
    return 0;
}
