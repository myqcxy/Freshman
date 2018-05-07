#include<stdio.h> 
char a[100];
int main()
{
	
	gets(a);
	int t=0, i;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!=' '&&a[i+1]==' ')
		t++;
	} 
	if(a[i-1]!=' ') t++;
	printf("%d\n", t);
	
	return 0;
}
