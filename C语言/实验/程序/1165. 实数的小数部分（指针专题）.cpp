#include<stdio.h>
#include<string.h>

int main()
{
	char s[101], p[100];
	scanf("%s", s);
	int i, j, n;
	for(i=0;s[i]!='.';i++)
	{
		
	}
	for(j=0,i++;s[i]!='\0';i++,j++)
	{
		p[j]=s[i];
	}
	p[j]='\0';
	n=strlen(p)-1;
	for(i=n;i>=0;i--)
	{
		if(p[i]=='0')
		{
			p[i]='\0';
		}
		else break;
	}
	if(strlen(p)==0) printf("No decimal part\n");
	else printf("0.%s\n", p);
		
	
	return 0;
}
