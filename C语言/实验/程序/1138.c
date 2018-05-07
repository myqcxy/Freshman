#include<stdio.h>
int main()
{
	char a[51];
	int i, t=0;
	gets(a);
	if(a[0]>='a'&&a[0]<='z'||a[0]>='A'&&a[0]<='Z'||a[0]=='_')
	{
		t++;
		for(i=1;a[i]!='\0';i++)
		{
			if(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z'||a[i]>='0'&&a[i]<='9'||a[i]=='_')
			t++;
			else 
			{
				t=0;
				break;
			}
		}
	}
	if(t>0) printf("yes\n");
	else printf("no\n");
	
	return 0;
}
