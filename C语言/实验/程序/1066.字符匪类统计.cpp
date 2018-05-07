#include<stdio.h>
#include<ctype.h>
#define N 1000
int main()
{
	int letter=0, digit=0, other=0;
	char ch;
	while(ch=getchar(),ch!='\n')
	{
		if(isalpha(ch))
		{
			letter++;
		}
		else if(isdigit(ch))
	    {
	    	digit++;
		}
		else
		{
			other++;
		}
	}
	printf("letter:%d\ndigit:%d\nother:%d\n", letter, digit, other);
	
	return 0;
}
