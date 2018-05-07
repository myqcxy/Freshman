#include<stdio.h>
int main()
{
	struct student
	{
		char num[9];
		char name[21];
		int chiScore, mathScore, engScore, score; 
	}a[100];
	int n, i, flag=0;
	scanf("%d", &n); 
	for(i=0;i<n;i++) 
	{
		scanf("%s%s%d%d%d", a[i].num, a[i].name, &a[i].chiScore, &a[i].mathScore, &a[i].engScore); 
		a[i].score=a[i].chiScore+a[i].mathScore+a[i].engScore; 
		if(a[flag].score<a[i].score) 
		{
			flag=i; 
		} 
	}
	 printf("%s %s %d %d %d", a[flag].num, a[flag].name, a[flag].chiScore, a[flag].mathScore, a[flag].engScore); 
	
	return 0; 
} 
