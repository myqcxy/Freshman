#include<stdio.h>

int main()
{
	char ch[20][50];
	int j, min=50, m=0, n, i;
	scanf("%d", &n);
	getchar();
	for(i=0;i<n;i++)
	{
		for(j=0;j<50;j++)
		{
		    scanf("%c", &ch[i][j]);
			if(ch[i][j]=='\n')
			{	
				break;
				
			}  
		} 
		if(j<min)
		    {
		        min=j;
			    m=i;
		    }
		
	
	}
	for(j=0;j<min;j++)
	{
		printf("%c", ch[m][j]);
	}	
	
	return 0;
}
