#include<stdio.h>

int main()
{
    float input;
    int count=0;
    scanf("%f",&input);
    while(input>=10)
    {
        input=input/10;
        count++;
    }
    while(input<1)
    {
        input=input*10;
        count--;
    }
    printf("%f-e%d\n",input,count);
    return 0;
}