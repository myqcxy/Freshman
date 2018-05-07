#include<stdio.h>
int main()
{
	int  i, b[200]={0}, c;
	char a[101];
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
		a[i]=a[i]+32;
		c=a[i];
		b[c]++;
	}
	c=97;
	for(i=97;i<122;i++)
	{
		if(b[i+1]>b[c])
		c=i+1;
	}
	printf("%c\n", c);
	return 0;
}
