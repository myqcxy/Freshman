#include<stdio.h> 
#include<string.h>
void reverse(char *p);
int main()
{
	char s[102];
	scanf("%s", s);
	int i,n=strlen(s)-1, t=0;
	for(i=n;s[i]=='0';i--)
	{
		t++;
		s[i]='\0';
	}
	reverse(s);
	printf("%s", s);
	while(t--) printf("0");
	putchar(10);
	
	
	
	return 0;
}
void reverse(char *p) 
{ 
 //函数求出str的逆转数并存入str。 
 	int i=0, j=strlen(p)-1;
	char s;
	while(i<j)
	{
		if(p[i]=='-') 
		{
			i++;
			continue;
		}
		
		s=p[i];
		p[i]=p[j];
		p[j]=s;
		i++;
		j--;
	}
	p[strlen(p)]='\0';
 	
 	
 	
 	
} 

