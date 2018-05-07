#include<stdio.h>
int main()
{
	int score, i, max=0;
	for(i=1;;i++)
	{
		scanf("%d", &score);
		if(score>max)
		{
			max=score;
		}
		if(score<0)
		break;
	} 
	printf("%d", max);
	
	
	return 0;
}
