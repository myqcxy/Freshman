#include<stdio.h>
int main()
{
	int year, month, n;
	scanf("%d%d",&year,&month);
	 switch(month)
	 {
	 	case 1:n=31;break;
	 	case 3:n=31;break;
	 	case 5:n=31;break;
	 	case 7:n=31;break;
	 	case 8:n=31;break;
	 	case 10:n=31;break;
	 	case 12:n=31;break;
	 	case 4:n=30;break;
	 	case 6:n=30;break;
	 	case 9:n=30;break;
	 	case 11:n=30;break;
	 	case 2:
	 		if(year%400==0||year%4==0&&year%100!=0)
	 		{
	 			n=29;
			 }
			 else
			 {
			 	n=28;}
			 break;
	}		 
	printf("%d",n);
	 
	return 0;
} 
