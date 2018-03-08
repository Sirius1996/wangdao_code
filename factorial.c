#include <stdio.h>
#include <stdlib.h>

void factorial(int num)
{
    int temp = 0, carry = 0;
    int i, j = 0, flag = 1;
    int ans[10000] = {0};

    ans[0] = 1;
    for(i = 1; i <= num; i++)
    {
        if(flag)
        {
            temp = ans[j] * i + carry;
            if(temp > 9)
            {
                flag = 0;
                carry = temp / 10;
                ans[j] = temp % 10;
                j++;
            }
        }
        else
        {
            
        }
    }
}

int main()
{
    int number;
    scanf("%d", &number);
    factorial(number);

    return 0;
}