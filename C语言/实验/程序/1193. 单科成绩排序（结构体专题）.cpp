#include<stdio.h>
#include<string.h>
int main()
{
	struct student
	{
		char num[14], name[21];
		int s[3];			
	}a[102], b;
	int i, n, j, k;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%s%s%d%d%d", a[i].num, a[i].name, &a[i].s[0], &a[i].s[1], &a[i].s[2]);
	}
	scanf("%d", &j);
	j--;
	for(i=0;i<n;i++)
	{
		for(k=i;k<n;k++)
		{
			if(a[k].s[j]>a[i].s[j])
			{
				b=a[k];
				a[k]=a[i];
				a[i]=b;
			}
			if(a[k].s[j]==a[i].s[j])
			{
				if(strcmp(a[i].num,a[k].num)>0)
				{
					b=a[i];
					a[i]=a[k];
					a[k]=b;
				}
			}
		}
			
	} 
	
	for(i=0;i<n;i++)
	{
		printf("%s %s %d %d %d\n", a[i].num, a[i].name, a[i].s[0], a[i].s[1], a[i].s[2]);
	}
	
	return 0;
}
