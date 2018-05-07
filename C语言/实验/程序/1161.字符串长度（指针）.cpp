#include<stdio.h>
int main()
{
	int len(char *sp);
	char a[100];
	int i;
	for(i=0;a[i-1]!='\n';i++)
	{
		a[i]=getchar();
	}
	printf("%d", len(a));
	
	return 0;
}
int len(char *sp)
{
	int i=0, d=0;
	while(sp[i]!='\n')
	{
		if(sp[i]!=' ')
		d++;
		i++;
	}
	return d;
} 
