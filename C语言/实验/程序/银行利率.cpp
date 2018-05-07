#include<stdio.h>
int main()
{
	char a, b, c, max;
	a=getchar();
	getchar();
	b=getchar();
	getchar();
	c=getchar();
	max=a;
    if(b>=max)
    max=b;
    if(c>=max)
    max=c;
	printf("%c", max);
	return 0;
}
