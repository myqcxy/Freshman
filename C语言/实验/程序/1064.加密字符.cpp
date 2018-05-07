#include<stdio.h>

int main()
{
	char a[10000];
	int j, i;
	for(i=0;scanf("%c", &a[i]),a[i]!='@';i++)
	{
		if(a[i]<='Z'&&a[i]>='A')
			a[i]+=32;
		 if(a[i]<'z'&&a[i]>='a')
		{
			a[i]=a[i]+1;
		}
		else if(a[i]=='z')
		{
			a[i]='a';
		}
	}
	for(j=0;j<i;j++)
	{
		printf("%c", a[j]);
	}
	return 0;
}
