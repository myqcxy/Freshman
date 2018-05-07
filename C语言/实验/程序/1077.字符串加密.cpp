#include<stdio.h>
#include<ctype.h> 
#define N 100
int main() 
{
	char a[N];
	gets(a);
	int i, k;
	scanf("%d", &k);
	for(i=0;a[i]!='\0';i++)
	{
		if(isalpha(a[i]))
		{
			if(a[i]>='a'&&a[i]<='z')
			{
				if((a[i]+k%26)<='z')
		    	{
					a[i]+=k%26;
		    	}
		    	else
		    	{
					a[i]=a[i]+k%26-26;
		    	}
			}
			if(a[i]>='A'&&a[i]<='Z')
			{
				if((a[i]+k%26)<='Z')
		    	{
					a[i]+=k%26;
		    	}
		    	else
		    	{
					a[i]=a[i]+k%26-26;
		   	 	}
			}
		}
		
	}
	printf("%s", a);
	
	
	return 0;
}
