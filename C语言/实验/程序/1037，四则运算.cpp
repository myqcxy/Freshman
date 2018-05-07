#include<stdio.h>
#include<math.h>
int main()
{
	double s1, s2;
	char op;
	scanf("%lf %c %lf", &s1, &op, &s2);
	switch(op)
	{
		case '+':printf("%.2f", s1+s2);break;
		case '-':printf("%.2f", s1-s2);break;
		case '*':printf("%.2f", s1*s2);break;
		case '/':
			if(fabs(s2)<(1e-10))
			{
				printf("Wrong input!");
			}
		    else
		    {
		    	printf("%.2f", s1/s2);
			};break;
		default:printf("Wrong input!");
	}
	
	
	return 0;
}
