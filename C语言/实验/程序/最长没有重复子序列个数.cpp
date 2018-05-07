#include<stdio.h>

int main()//abcabcbb
{
	char s[100];
	
	scanf("%s", s);
	int a[256];
	for(int i = 0;i < 256;i++)
		a[i] = -1;
	int start = -1;
	int max = 0;
	for(int i = 0;s[i]!='\0';i++)
	{
		if(a[s[i]] > start) start = a[s[i]];
		a[s[i]] = i;
		
		max = max > i - start ? max : i - start;
	}
	printf("%d\n", max);
	
	return 0;
}
