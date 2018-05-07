#include<stdio.h>
#define N 101
#include<string.h>
int main()
{
	struct student
	{
		char id[14], name[21];
		int score1, score2, score3, score;
	};
	struct student a[N], b;
	int i, n, j;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%s%s%d%d%d", a[i].id, a[i].name, &a[i].score1, &a[i].score2, &a[i].score3);
		a[i].score=a[i].score1+a[i].score2+a[i].score3;
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[j].score>a[i].score)
			{
				b=a[j];
				a[j]=a[i];
				a[i]=b;
			}
			if(a[j].score==a[i].score)
			{
				if(strcmp(a[i].name,a[j].name)>0)
				{
					b=a[j];
					a[j]=a[i];
					a[i]=b;
				}
				if(strcmp(a[i].name,a[j].name)==0)
				{
					if(strcmp(a[i].id,a[j].id)>0)
					{
						b=a[j];
						a[j]=a[i];
						a[i]=b;
					}
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%s %s %d %d %d %d\n", a[i].id, a[i].name, a[i].score1, a[i].score2, a[i].score3, a[i].score);
	}
	
	return 0;
}
