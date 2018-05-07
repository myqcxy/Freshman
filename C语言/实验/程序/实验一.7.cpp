#include<stdio.h>
#include"cal.c"
int main()
{
	int a, b;
	char ch;
	while(1)
	{
		scanf("%d%c%d", &a, &ch,&b);
		if(ch=='+')
		printf("%d%c%d=%d\n", a, ch,b,ADD(a,b));
		else printf("%d%c%d=%d", a, ch, b, SUB(a,b));
	}
	
	
	
	return 0;
}
