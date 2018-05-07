#include<stdio.h> 
int main()
{
	char a[201], ch1='a', ch2='A'; 
	int i;
	
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{		 
		if(a[i]>='a'&&a[i]<='z')
		{
			if(a[i]>ch1) ch1=a[i];
		}
		if(a[i]>='A'&&a[i]<='Z')
		{
			if(a[i]>ch2) ch2=a[i];
		}
	}
	for(i=0;a[i]!='\0';i++)
	{
		if(ch1==ch2==a[i])
			printf("%c(max)", a[i]);
		else if(ch1>ch2&&a[i]==ch1)
			printf("%c(max)", a[i]);
		else if(ch1<ch2&&a[i]==ch2)
			printf("%c(max)", a[i]);
		else
			printf("%c", a[i]);
	}
	
	return 0;
}
