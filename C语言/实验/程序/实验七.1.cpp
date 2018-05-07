#include<stdio.h> 
#include<math.h> 
int main()
{
	struct print
	{
		float x, y, dis;	
	}; 
	struct print a[2];
	int i; 
	for(i=0;i<2;i++)
	{ 
		scanf("%f%f", &a[i].x, &a[i].y); 
		a[i].dis=sqrt(a[i].x*a[i].x+a[i].y*a[i].y); 
	} 
	if(a[0].dis>a[1].dis) 
		printf("(%.0f,%.0f)", a[0].x, a[0].y); 
	else
		printf("(%.0f,%.0f)", a[1].x, a[1].y);

	return 0; 
} 
