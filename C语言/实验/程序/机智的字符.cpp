#include<stdio.h>
int main()
{
	int i, j, m, n, t=0;
	char a[20][20];
	scanf("%d%d", &m, &n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(t>=26)
			{
				t=0;
			}
			
			a[i][j]='a'+t;
			t++;
		}
	}
	for(i=0;i<m;i++)
	{
		printf(">");
		for(j=0;j<n;j++)
		{
			printf("%c", a[i][j]);
		}
		printf("<");
		putchar(10);
			
	}

	return 0;
}
