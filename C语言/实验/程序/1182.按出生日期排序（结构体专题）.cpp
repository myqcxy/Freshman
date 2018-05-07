#include<stdio.h>
int main()
{
	struct boitime
	{
		int year, month, day;
	};
	struct friendb
	{
		char name[9];
		struct boitime birthday;
	}a[10], b;
	int n, i, j;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%s%d%d%d", &a[i].name, &a[i].birthday.year, &a[i].birthday.month, &a[i].birthday.day);	
	}
	for(j=0;j<n;j++)
	{
		for(i=j;i<n;i++)
	    {
			if(a[j].birthday.month>a[i].birthday.month||a[j].birthday.month==a[i].birthday.month&&a[j].birthday.day>a[i].birthday.day)
			{
				b=a[j];
				a[j]=a[i];
				a[i]=b;
			}
    	}
  }
	for(i=0;i<n;i++)
	{
		printf("%s %d-%02d-%02d\n", a[i].name, a[i].birthday.year, a[i].birthday.month, a[i].birthday.day);
	}
 	
	
	return 0;
}
