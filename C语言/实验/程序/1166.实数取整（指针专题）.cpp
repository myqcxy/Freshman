#include<stdio.h>
#include<string.h>
char *strrev1(char *p);
int main()
{
	char s[101], p[100];
	scanf("%s", s);
	int i, j, n=0;
	for(j=0,i=0;s[i]!='.'&&s[i]!='\0';i++,j++)
	{
		p[j]=s[i];
	}
	p[j]='\0';
	strcpy(p,strrev1(p)); 
	n=strlen(p)-1;
	for(i=n;p[i]=='0';i--)
	{
		p[i]='\0';
	}

	strcpy(p,strrev1(p));
	
	if(n==0) printf("0\n");
	else printf("%s\n", p);
	
	return 0;
}
char *strrev1(char *p)
{
	int i=0, j=strlen(p)-1;
	char s;
	while(i<j)
	{
		s=p[i];
		p[i]=p[j];
		p[j]=s;
		i++;
		j--;
	}
	p[strlen(p)]='\0';
	return p;
	
}
