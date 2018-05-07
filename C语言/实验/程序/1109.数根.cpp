#include<stdio.h> 
int main()
{
	int digitSum(int n);
	int n;
	scanf("%d", &n);
	while(n>=10)
	{
		n=digitSum(n);
	}
	printf("%d\n", n);
	
	return 0;
}
int digitSum(int n) 
{ 
	int a=0;
	while(n>0)
	{
		a+=n%10;
		n=n/10;
	 } 
	 return a;
//函数返回n的各位数字之和 
} 
