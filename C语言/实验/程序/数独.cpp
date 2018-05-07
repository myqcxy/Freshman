#include<stdio.h>
int t, j, m, n, i,a[9][9]={0};
int main()
{
	
	void input();
	void panduanhang();
	scanf("%d", &t);
	while(t--)
	{
		input();
	}
	
	return 0;
}
void input()
{
	for(i=0;i<9;i++)
		{
			for(j=i;j<9;j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
}
void panduanhang()
{
	int b=0;
	for(i=0;i<9;i++,b++)
	{
		for(j=0;j<9;j++)
		{
			if(a[i][b]==a[j][b])
			printf("no\n");
		}
	}
	
}
void panduanlie()
{
	int b=0;
	for(i=0;i<9;i++,b++)
	{
		for(j=0;j<9;j++)
		{
			if(a[b][i]==a[b][j])
			printf("no\n");
		}
	}
}

