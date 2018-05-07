#include<stdio.h>
#include<string.h>
#define N 110

int main(void)
{
	char str[N], *p=str,*q;

	scanf("%s",str);

	while(*p == '0')
		p++;

	if(*p== '.')
		p--;

	q=strchr(p,'.');
	if(q != NULL)
		*q = '\0';

	puts(p);
	return 0;
}
