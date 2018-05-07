#include<stdio.h>
int dedup(int a, int b, int c);

int main()
{
	int a = 0, b = 0, c = 0;
	int i = 0;
	for (i = 100; i < 333; i++)
	{
		a = i;
		b = 2 * a;
		c = 3 * a;
		dedup(a, b, c);
	}
   
	return 0;
}

int dedup(int a, int b, int c)
{
	int l = 0, m = 0;
	int dup[10] = { 0, };
        //计算各个位的数字
	dup[0] = a % 10;
	dup[1] = a / 10 % 10;
	dup[2] = a / 100;
	dup[3] = b % 10;
	dup[4] = b / 10 % 10;
	dup[5] = b / 100;
	dup[6] = c % 10;
	dup[7] = c / 10 % 10;
	dup[8] = c / 100;
	for (l = 0; l < 9; l++)
	{
		for (m = l + 1; m < 9; m++)
		{
			if (dup[l] == dup[m] || dup[l] == 0)//各个位没有相等的数字，且不等于零
			{
				return 0;
			}
		}
	}
	printf("%d %d %dn", a, b, c);
	return 0;
}			
