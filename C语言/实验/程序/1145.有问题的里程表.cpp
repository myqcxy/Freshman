#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int t=0, i, a;
	char num[10];
	scanf("%s", num);
	a=strlen(num)-1;
	
	for(i=0;a>=0;i++)
	{
		if(num[i]>'4') num[i]-=1;
		t+=(num[i]-'0')*pow(9,a);
		a--;
	}
		printf("%d\n", t);

	
	return 0;
}
