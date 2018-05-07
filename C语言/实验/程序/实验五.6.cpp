#include<stdio.h>
int main()
{
	char a[80];
	int i, n, t=0;
	for(i=0;i<80;i++)
	{
		scanf("%c", &a[i]);
		if(a[i]=='\n')
		break;
		else
		{
			if(a[i]!='A'&&a[i]!='E'&&a[i]!='I'&&a[i]!='O'&&a[i]!='U'&&a[i]>'A'&&a[i]<'Z')
			t++;
		}
	} 
	printf("%d", t);
	
	return 0;
}
