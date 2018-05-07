#include<stdio.h>
int main()
{
	struct boitime
	{
		int year, month, day;
	};
	struct friendb
	{
		char name[20];
		struct boitime birthday;	
	}a[10];
	int n, i,flag=0;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%s%d%d%d", &a[i].name, &a[i].birthday.year, &a[i].birthday.month, &a[i].birthday.day);
	}
	for(i=0;i<n;i++)
	{
		if(a[flag].birthday.year==a[i].birthday.year)
		{
			if(a[flag].birthday.month<a[i].birthday.month)
			{
				flag=i;
			}
			
			if(a[flag].birthday.month==a[i].birthday.month)
			{
				if(a[flag].birthday.day<a[i].birthday.day)
				flag=i;
			}
		}
		if(a[flag].birthday.year<a[i].birthday.year)
		flag=i;
	}
 	printf("%s %d-%02d-%02d", a[flag].name, a[flag].birthday.year, a[flag].birthday.month, a[flag].birthday.day);
	
	
	return 0;
}
