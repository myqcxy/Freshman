#include<stdio.h>
int main()
{
	int n, i, t;
	char a[1001];
	scanf("%d ", &n);
	while(n--)
	{
		t=0;
		gets(a);
		for(i=0;a[i]!='\0';i++)
		{
			if(a[i]>='0'&&a[i]<='9')
			t++;
		}
		printf("%d\n", t);
		
		
	}
	
	
	return 0;
}
