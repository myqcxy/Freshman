#include<stdio.h>
#define N 1000
int main()
{
	int t, i, n;
	char a[N];
	scanf("%d", &t);
	getchar();
	while(t--)
	{
		n=0;
		scanf("%s", a);
		for(i=1;a[i-1]!='\0';i++)
		{
			if(a[i-1]=='(')
			n++;
			if(a[i-1]==')')
			n--;
			if(a[i-1]=='B')
			{
				printf("%d\n", n);
				break;
			}
		}
		
		
	}
	
	
	return 0;
}
