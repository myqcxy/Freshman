#include<stdio.h>
#include<string.h>
#include<math.h>
char a[101];
int b[101];
int main()
{
	int i, t=0, m, sum=0;
	gets(a); 
	for(i=0;a[i]!='\0';i++)
		if(a[i]>='0'&&a[i]<='9')
		{
			b[t]=a[i]-'0';
			t++;
		}
		m=t-1;
	for(i=0;i<t;i++)
	{
		sum+=b[i]*pow(10,m);
		m--;
		
	}
		printf("%d\n", sum*2);
	return 0;
}
