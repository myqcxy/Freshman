#include<stdio.h>
int main()
{
	struct student
	{
		char num[9], name[21];
		int chiSore, mathScore, engScore, score;
	 }; 
	 struct student a[100];
	 int i, n, flag=0;
	 scanf("%d", &n);
	 for(i=0;i<n;i++)
	 {
	 	scanf("%s%s%d%d%d", a[i].num, a[i].name, &a[i].chiSore, &a[i].mathScore, &a[i].engScore);
	 	a[i].score=a[i].chiSore+a[i].mathScore+a[i].engScore;
	 }
	for(i=0;i<n;i++)
	{
		if(a[flag].score<a[i].score)
		{
			flag=i;
		}
	}
	printf("%s %s %d %d %d\n", a[flag].num, a[flag].name, a[flag].chiSore, a[flag].mathScore, a[flag].engScore);
	 
	return 0; 
} 
