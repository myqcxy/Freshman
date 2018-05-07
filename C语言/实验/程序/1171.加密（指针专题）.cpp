#include<stdio.h>
#include<string.h>
void encrypt(char *plain, char *cipher);
int main()
{
	char a[201], b[402];
	gets(a);
	encrypt(a,b);
	puts(b);
	
	
	return 0;
}
void encrypt(char *plain, char *cipher) 
{ 
 	//把原文字符串plain加密后存入字符串cipher 
 	int i,j;
 	char a;
 	for(i=0;plain[i]!='\0';i++)
 	{
 		plain[i]-=24;
 //		printf("%d",plain[i]);
	}
	for(i=0,j=0;plain[i]!='\0';i++,j+=2)
	{
		cipher[j]=plain[i]/10+'0';
//		printf("%c",plain[i]/10);
		cipher[j+1]=plain[i]%10+'0';
	}
	cipher[j]='\0';
	j--;
	
	i=0;
	while(i<j)
	{
		a=cipher[i];
		cipher[i]=cipher[j];
		cipher[j]=a;
		i++;
		j--;
	}
//	for(;j>=0;j--) printf("%c",cipher[j]);
	 
} 

