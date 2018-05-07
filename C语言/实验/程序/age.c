#include<stdio.h> 
int main()
{
	int i = 28;
	int num = 0;
	for(;i < 100;i++)
	{
		if(isSame(i,i-27))
			num++;
	}
	printf("%d\n", num);
}
int isSame(int a ,int b)
{
	a = a/10 + a%10*10;
	return a == b;
}
