#include<stdio.h>
int main()
{
	int run(int year);
	int year, month, day, sum=0, i;
	scanf("%d-%d-%d", &year, &month, &day);
	int a[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};	
	
	for(i=0;i<month;i++)
	sum+=a[run(year)][i];
	printf("%d\n", sum+day);
	
	return 0;
}
int run(int year)
{
	if(year%4==0&&year%100!=0||year%400==0)
	return 1;
	else return 0;
}
