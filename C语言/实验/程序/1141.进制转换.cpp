#include<stdio.h>
int main()
{
	void convert(int n, char str[]);
	int n;
	char str[40];
	scanf("%d", &n);
	convert(n,str);
	return 0;
}
void convert(int n, char str[])
{
	int j, i;
	if(n==0) printf("%d", 0);
	for(i=0;n>0;i++)
	{
		str[i]=n%2;
		n/=2;
			
	}
	j=i;
	for(i=j-1;i>=0;i--)
	printf("%d", str[i]);
} 
