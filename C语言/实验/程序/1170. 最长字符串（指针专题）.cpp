#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	void maxLenStr(char *str[], int n, int *max);
	char *a[81], b[81];
	int n=0;
	int max=0;
	while(gets(b),strcmp(b,"****")!=0)
	{
		a[n]=(char *)malloc(strlen(b)+1);
//		printf("asdf\n");
		strcpy(a[n],b);
		n++;
	}
	
	maxLenStr(a,n,&max);
	puts(a[max]);
//	putchar(10);
	
	
	return 0;
}
void maxLenStr(char *str[], int n, int *max) 
{ 
//从字符串数组str中找出最长的一个字符串，并将其下标存入形参指针max所指内存。 
	int i;
	*max=0;
	for(i=0;i<n;i++)
	{
//		puts(str[i]);
		if(strlen(str[*max])<strlen(str[i]))
		*max=i;
//		printf("%d\n", *max);
	}
		
	
}
