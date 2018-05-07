#include<stdio.h>
int main()
{
	char a[80];
	int i, t=0;
	for(i=0;i<80;i++)
	{
		scanf("%c", &a[i]);
		if(a[i]==(10))
		break;
		if(a[i]!='A'&&a[i]!='E'&&a[i]!='I'&&a[i]!='O'&&a[i]!='U'&&a[i]>='A'&&a[i]<='z')
		{
			t++;
			printf("%c", a[i]);
		}
		
	} 
	printf("\n%d", t);
	

    return 0; 
}
