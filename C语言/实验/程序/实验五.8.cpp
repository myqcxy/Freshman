#include<stdio.h>

int main()
{
	char ch[50];
	int i;
	for(i=0;i<50;i++)
	{
		scanf("%c", &ch[i]);
		if(ch[i]=='\n')
		break;
		if(ch[i]>='0'&&ch[i]<='9')
		{
			printf("%d,", (int(ch[i])-48)*2);
		}	
	}
	
	return 0;
}
