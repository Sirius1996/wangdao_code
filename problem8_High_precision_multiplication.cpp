#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    vector<int> res;
    int carry=0;
    int times;
    cin>>times;
    int temp=times;
	while (temp != 0)
	{
		int a = temp % 10;
		res.push_back(a);
		temp = temp / 10;
	}
    while(times!=1)//关键部分：分解成数组，每一位自乘，本位留下余数，高的部分进位，一直到最后
    {
		times--;

        for(int j=0;j<res.size();j++)
        {
            int save=res[j]*times+carry;
            res[j]=save%10;
            carry = save/10;
        }
        if(carry!=0)
        {
            while(carry!=0)
            {
                res.push_back(carry%10);
                carry=carry/10;
            }
        }
    }
	for (int ptr = res.size() - 1; ptr >= 0; ptr--)
		cout << res[ptr];

	system("pause");
    return 0;
}
