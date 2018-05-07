#include<stdio.h> 
#include<string.h>
char a[50]="1+2=3";
int Presentation(char s[],int length_s)
{
	int i,count;
	count = 0;

	for(i = 0;i < length_s;i++)
	{
		if(s[i] == '1'||s[i]=='2'||s[i]=='3'||s[i]==' '||s[i]=='='||s[i]=='+')
		count++;
	}
	if(length_s == count)
	return 1;
	return 0;
}
int main()
{
	int t;
	scanf("%d", &t);

	while(t--)
	{
		char s[50],start[6],end[4];
		 int i;
		scanf("%s", start);
		getchar();
		for(i = 0;i < 50;i++)
		{
			scanf("%c", &s[i]);
			if(s[i] == '\n')
			break;
		}
		
		scanf("%s", end);
		if(strstr(s,a))
		printf("Accepted\n");
		else if(Presentation(s,i))
		 	printf("Presentation Error\n");
		else printf("Wrong Answer\n");
		
		
	}
	
	
	
	
	
	return 0;
}
