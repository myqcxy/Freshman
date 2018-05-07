#include<stdio.h>
#include<ctype.h>
int main()
{
	char ch[1111];
	int i, t=0;
	gets(ch);
	if(isdigit(ch[0]))
	t++;
	for(i=1;ch[i]!='\0';i++)
	{
		if(isdigit(ch[i])&&(isalpha(ch[i-1])||isblank(ch[i-1])))
		t++;
		if(ch[i]=='0'&&(isalpha(ch[i-1])||isblank(ch[i-1]))&&(isalpha(ch[i+1])||isblank(ch[i+1])))
		t++;
	}
	printf("%d\n", t);
	
	
	return 0;
}
