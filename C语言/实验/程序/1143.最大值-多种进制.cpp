#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int KToD(char str[], int k);
	int n, t=0, k;
	char a[32];
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s%d", a, &k);
		if(KToD(a,k)>t) t=KToD(a,k);
	}
	printf("%d\n", t);
	
	
	return 0;
}
int KToD(char str[], int k)
{
	int a, i, b=0;
	a=strlen(str)-1;
	for(i=0;a>=0;i++)
	{
		b+=(str[i]-'0')*pow(k,a);
		a--;
	}
	return b;
//函数返回k进制数str对应十进制整数
}
