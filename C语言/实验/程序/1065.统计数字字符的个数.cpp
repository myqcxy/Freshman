#include<stdio.h>
#define N 1000 
#include<ctype.h>
int main()
{
	char ch[N];
	int i, j=0;
	gets(ch);
	for(i=0;;i++)
	{
		if(ch[i]=='\0')
			break;
		if(ch[i]>='0'&&ch[i]<='9')
	    {
			j++;
		} 
	}

	printf("%d\n", j);
	
	
	return 0;
}
