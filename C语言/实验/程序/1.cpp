#include<stdio.h>
#include<ctype.h>
int main()
{
	char a[101], i;
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]==' '&&a[i+1]>='a'&&a[i+1]<='z')
		a[i+1]=a[i+1]-32;
	}
	if(a[0]!=' '&&a[0]>='a'&&a[0]<='z')
	a[0]=a[0]-32;
	puts(a);
	
	return 0;
}
