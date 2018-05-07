#include<stdio.h>
int main()
{
	int n, year, month, day;
	scanf("%d", &n);
	while(n>0)
	{
		scanf("%*6d%4d%2d%2d%*4d", &year, &month, &day);
		printf("%d-%02d-%02d\n", year, month, day);
		
		n--;
	 } 
	
	return 0;
}
