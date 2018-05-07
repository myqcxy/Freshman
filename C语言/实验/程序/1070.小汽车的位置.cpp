#include<stdio.h>
int main()
{
	int time, command,time1=0, x=0, y=0, d=0;
	while(scanf("%d%d", &time, &command)!=EOF)
	{
		
		if(command==1)
		{
			d++;
			d=d%4; 
		}
		
		if(command==2)
		{
			d--;
			d=d%4;
		}
		if(d==0)
			y+=(time-time1)*10;
		if(d==1)
			x-=(time-time1)*10;
		if(d==2)
			y-=(time-time1)*10;
		if(d==3)
			x+=(time-time1)*10;
		time1=time;
		if(command==3)
			break;
	}
	printf("%d %d", x, y);
	
	return 0;
}
