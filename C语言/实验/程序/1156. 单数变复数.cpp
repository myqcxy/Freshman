#include<stdio.h>
#include<string.h>
int main()
{
	char a[25];
	scanf("%s", a);
	int i, t=1;
	i=strlen(a)-1;
	if(a[i]=='y') 
	{
		a[i]='i';
		a[i+1]='e';
		a[i+2]='s';
		t=0;
		a[i+3]='\0';
	}
	if(a[i]=='s'||a[i]=='x'||a[i]=='o'||a[i]=='h'&&(a[i-1]=='c'||a[i-1]=='s'))
	{
		a[i+1]='e';
		a[i+2]='s';
		t=0;
		a[i+3]='\0';
	}
	if(t)
	{
		a[i+1]='s';
		a[i+2]='\0';
	}
	printf("%s", a);
	
	
	return 0;
}
