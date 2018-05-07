#include<stdio.h>
#include<ctype.h>
#define N 1000
int alpha=0, digit=0, blank=0, other=0;
void sta(char ch[]);
char ch[N];

int main()
{
	
	
	gets(ch);
	sta(ch);
	printf("%4d%4d%4d%4d", alpha, digit, blank, other);
	
	return 0;
}
void sta(char ch[])
{
	int i;
	for(i=0;ch[i]!='\0';i++)
	{
		if(isalpha(ch[i]))
		{
			alpha++;
		}
		else if(isdigit(ch[i]))
		{
			digit++;
		}
		else if(isblank(ch[i]))
		{
			blank++;
		}
		else
		{
			other++;
		}
	}
}
