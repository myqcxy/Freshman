#include<stdio.h>
#define N 100
struct date
	{
		int year;
		int month;
		int day;
	};
typedef struct friends
	{
		char name[20];
		struct date birthday;
	}age;
int main()
{
	age a[N]; 
	int n,i,j;
	int k,l,m,w;
	int max1=0,max2=0,max3=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s%d%d%d",a[i].name,&a[i].birthday.year,&a[i].birthday.month,&a[i].birthday.day);
	}
	for(i=0;i<n;i++)
	{

		if(max1<a[i].birthday.year)
		{	
			max1=a[i].birthday.year;
			j=i;
		}
	}
	//出生年相等时	
	for(k=j;k<n;k++)	
	{		
		if(max2<a[k].birthday.month)
			{	
				max2=a[k].birthday.month;
				l=k;
			}
	}
	//出生月相等时
	for(m=l;m<n;m++)		
	{			
		if(max3<a[m].birthday.day)		
		{			
			max3=a[m].birthday.day;		
			w=m;			
		}		
	}	
	
	for(i=0;i<n;i++)
	{
		if(a[i].birthday.year==a[j].birthday.year&&a[i].birthday.month==a[l].birthday.month&&a[i].birthday.day==a[w].birthday.day)
		{
			printf("%s %d %d %d\n",a[i].name,a[i].birthday.year,a[i].birthday.month,a[i].birthday.day);
		}
	}	
	return 0;
}
