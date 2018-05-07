#include<stdio.h>
#include<string.h>
int main()
{
	void dTok(int n, int k, char str[]);
	int n;
	scanf("%d", &n);
	char a2[32], a3[32], a7[32], a8[32];
	dTok(n,2,a2);
	dTok(n,3,a3);
	dTok(n,7,a7);
	dTok(n,8,a8);
	/*printf("%s\n", strrev(a2));
	printf("%s\n", strrev(a3));
	printf("%s\n", strrev(a7));
	printf("%s\n", strrev(a8));*/
	return 0;
}
void dTok(int n, int k, char str[]) 
{ 
	int i;
	for(i=0;n>0;i++)
	{
		str[i]=n%k+'0';
	//	printf("%c,", str[i]);
		n=n/k;
	}
	for(i=i-1;i>=0;i--)
	printf("%c", str[i]);
	putchar(10);
//	printf("%s\n", strrev(str));
//将n转化为k进制数，存入str 
} 
