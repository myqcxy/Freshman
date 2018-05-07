#include<stdio.h>
#include<string.h>
int main()
{
	int n, t, i, j;
	char a[101];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", a);
		scanf("%d", &n);
		for(i=0;a[i]!='.';i++)
		{
		}
		if(i+n>=strlen(a)) printf("0\n");
		else printf("%c\n", a[i+n]);
		
	}
	return 0;
}
