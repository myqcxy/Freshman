#include<stdio.h>
#include<string.h>
int main()
{
	struct info
	{
		char name[10];
		int votes;
	}a[5]={{"zhang",0},{"wang",0},{"zhao",0},{"liu",0},{"miao",0}};
	int n, i, j;
	char b[10];
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%s", b);
		for(j=0;j<5;j++)
		{
			if(strcmp(b,a[j].name)==0)
			a[j].votes++;
		}
	}
	for(i=0;i<5;i++)
	{
		printf("%s %d\n", a[i].name,a[i].votes);
	}
	
	return 0;
}
