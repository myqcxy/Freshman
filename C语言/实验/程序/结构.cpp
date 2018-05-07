#include<stdio.h>
int main()
{
	struct person
	{
		char name[20];
		int id;
		double score;
	};
	struct person a[3];
	int i, j=1;
	for(i=0;i<3;i++)
	{
		printf("ÇëÊäÈëÐÕÃû£º\n");
		while(a[j-1]!='\n')
		{
			scanf("%s", &a[i].name;
			j++;
		}
		
		printf("ÇëÊäÈëºÅÂë£º\n");

		
		scanf("%d", &a[i].id[i]);
		
		
		printf("ÇëÊäÈë³É¼¨£º\n"); 
		scanf("%lf", &a[i].score[i]); 
	}
	printf("ÐÕÃû£º  ºÅÂë£º   ³É¼¨\n");
	for(i=0;i<3;i++)
	{
	    printf("%s  ", a[i].name);
	    printf("%5d   %.2f", a[i].id, a[i].score);
	}

	
	return 0;
}
