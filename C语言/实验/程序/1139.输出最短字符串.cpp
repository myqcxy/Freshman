#include<stdio.h>
#include<string.h>
int main()
{
	int n, t=1000, i;
	char a[1001], b[1001];
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		gets(a);
		for(i=0;a[i]!='\0';i++)
		{
			if(strlen(a)<t)
			{
				t=strlen(a);
				strcpy(b,a);
			}
			
		}
	} 
	puts(b);
	return 0;
}
