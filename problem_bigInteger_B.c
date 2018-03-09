/*大数阶乘问题*/
#include <stdio.h>
#include <stdlib.h>

void factorial(int num)
{
	int temp = num, carry = 0;
	int res[1000000] = { 0 };
	int i = 0;

	/*从高到低开始阶乘，例如15！= 15*14*...*2*1
	*/
	while (temp != 0)
	{
		res[i] = temp % 10;
		temp = temp / 10;
		i++;
	}

	while (num != 1)
	{
		num--;
		for (int j = 0; j < i; j++)
		{
			int ans = 0;
			ans = res[j] * num + carry;
			res[j] = ans % 10;
			carry = ans / 10;
		}
		if (carry != 0)
		{
			while (carry != 0)
			{
				res[i++] = carry % 10;
				carry = carry / 10;
			}
		}
	}

	for (int k = i-1; k >= 0; k--)
		printf("%d", res[k]);
}

int main()
{
	int number;
	scanf("%d", &number);
	factorial(number);
	system("pause");
	return 0;
}