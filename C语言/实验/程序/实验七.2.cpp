#include<stdio.h>
int main()
{
	struct birthday
	{
		int year, month, day; 
	}; 
	struct friends
	{
		char name[9];
		struct birthday bir; 
	
	}a[10];
	int n, i, flag=0;
	scanf("%d", &n);
	for(i=0;i<n;i++) 
	{
		scanf("%s%d%d%d", a[i].name, &a[i].bir.year, &a[i].bir.month, &a[i].bir.day); 
		if(a[flag].bir.year<a[i].bir.year)
		{
			flag=i;		
		} 
		if(a[flag].bir.year==a[i].bir.year) 
		{
			if(a[flag].bir.month<a[i].bir.month) 
			{ 
				flag=i; 
			}
			if(a[flag].bir.month==a[i].bir.month) 
			{
				if(a[flag].bir.day<a[i].bir.day)
				flag=i; 
			} 
		} 
	} 
	printf("%s %d-%d-%d", a[flag].name, a[flag].bir.year, a[flag].bir.month, a[flag].bir.day); 

	return 0; 
} 
