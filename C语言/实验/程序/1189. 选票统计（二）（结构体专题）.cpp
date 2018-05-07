#include<stdio.h>
#include<string.h>
int main()
{
	struct info
	{
		char name[20];
		int votes;
	}a[501];
	int n, i, j, d=0;
	for(i=0;i<501;i++)
	{
		scanf("%s", a[i].name);
	//	printf("%s\n", a[i].name);
		if(strcmp(a[i].name,"#")==0) 
		break;
		for(j=0;j<=i;j++)
		{
			if(strcmp(a[i].name,a[j].name)==0)
			a[j].votes++;
		}
	}
	for(j=0;j<i;j++)
	{
		if(a[j].votes>a[d].votes)
		d=j;
	}
	printf("%s\n", a[d].name);
	return 0;
}
