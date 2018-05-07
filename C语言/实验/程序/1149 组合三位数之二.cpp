#include<stdio.h>
int check(int a, int b,int c);
int main()
{
	int i;
	for(i = 100;i < 333;i++)
	{
		if(check(i,2*i,3*i))
		printf("%d %d %d\n", i,2*i,3*i);
		
	}
	
	return 0;
}
int check(int a, int b,int c)
{
	int  t, m;
	int list[9];
		list[0] = a / 100;
		list[1] = a / 10 % 10;
		list[2] = a % 10;
		list[3] = b / 100;
		list[4] = b / 10 % 10;
		list[5] = b % 10;
		list[6] = c / 100;
		list[7] = c / 10 % 10;
		list[8] = c % 10;
		for(t = 0;t < 9;t++)
		for(m = t+1;m < 9;m++)
			if(list[t] == list[m]||list[t]==0)
			return 0;
			
		return 1;
}
