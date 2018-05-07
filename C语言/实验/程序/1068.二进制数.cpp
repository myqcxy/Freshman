#include<stdio.h>
#define N 1000
int main()
{
	char a[N];
	int i, d=0; 
	scanf("%s", a);
	for(i=0;a[i]!='\0';i++)
	{
		d=d*2+a[i]-'0';
	}
	printf("%d", d);
	
	
	return 0;
}
