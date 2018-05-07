#include<stdio.h>
#include<string.h>
int main()
{
	char a[1005];
	char b[1005];
	char ptr[1005];
	int n, s=0;
	scanf("%s%d", a, &n);
	memset(b,'1',n);
	while(strstr(a,b)!=NULL)
	{
		s++;
		strstr(a,b)[0]='0';
	}
	printf("%d\n", s);
	
	
	return 0;
}
