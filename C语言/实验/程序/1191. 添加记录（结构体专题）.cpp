#include<stdio.h>
#include<string.h>
int main()
{
	struct student
	{
		char num[13], name[21];
		int s1, s2, s3;
		
	}a[102], b;
	int n, i, j;
	scanf("%d", &n);
	for(i=0;i<=n;i++)
	{
		scanf("%s%s%d%d%d", a[i].num, a[i].name, &a[i].s1, &a[i].s2, &a[i].s3);
	}
	for(i=0;i<n;i++)
	{
		if(strcmp(a[i].num,a[n].num)==0)
		break;
	}
	if(i==n)
	{
		for(i=0;i<=n;i++)
		{
			if(strcmp(a[i].num,a[n].num)>0)
			{
				b=a[i];
				a[i]=a[n];
				a[n]=b;				
			}
			printf("%s %s %d %d %d\n", a[i].num, a[i].name, a[i].s1, a[i].s2, a[i].s3);
		}
	}
	else
	{
		printf("error!\n");
	}
	
	return 0;
}
