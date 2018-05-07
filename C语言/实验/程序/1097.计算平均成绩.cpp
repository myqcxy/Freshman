#include<stdio.h>
int main()
{
	double i=0.0;
	double ave=0.0;
	char ch;
	while(ch=getchar(),ch!='\n')
	{
		i++;
		switch(ch)
		{
			case 'A':ave+=95;break;
			case 'B':ave+=85;break;
			case 'C':ave+=75;break;
			case 'D':ave+=65;break;
			case 'E':ave+=40;break;
		}
		
	}
	printf("%.1f\n", ave/i);
	 
	
	return 0;
}
