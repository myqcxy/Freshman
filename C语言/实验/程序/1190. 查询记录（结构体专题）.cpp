#include<stdio.h> 
#include<string.h>
int main()
{
	struct stu
	{
		char num[13], name[22];
		int s1, s2, s3;
	}a[101];
	char Num[13];
	int n, i;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%s%s%d%d%d", a[i].num,a[i].name,&a[i].s1,&a[i].s2,&a[i].s3);
	}
	scanf("%s", Num);
	for(i=0;i<n;i++)
	{
		if(strcmp(Num,a[i].num)==0)
		{
			break;
		}
	}
	if(i==n) printf("Not Found\n");
	else printf("%s %s %d %d %d\n", a[i].num, a[i].name,a[i].s1, a[i].s2,a[i].s3);
	
	return 0;
}
