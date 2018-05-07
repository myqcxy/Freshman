#include<stdio.h>

int a[]={23, -8, -29, -16, 46, -49, 46, 43, 
44, 43, -10, -15, -20, 0, -38, 27, 
15, -34, -12, -36, 19, 30, -49, 2, 
24, -35, -1, 4, 7, -29, 12, -31, 
-48, -33, -32, 4, 47, -25, -10, -28}; 

void maximumSubSequence(int a[], int len, int *start, int *end, int* max)
{
	int i, j, k, sum;
	*max = a[0];
	for(i = 0; i < len; i++)
		for( j = i; j < len; j++)
		{
			sum = 0;
			for( k = i; k <= j; k++)
				sum += a[k];
			if( sum > *max)
			{
				*max = sum;
				*start = i;
				*end = j;
			}
		}
	
	
	
}
int main()
{
	int start, end, max;
	int i;
	maximumSubSequence(a, sizeof(a)/sizeof(int), &start, &end, &max);
	printf("和最大子序列为从第%d项到第%d项", start+1, end+1);
	printf("\n分别是：\n");
	for( i = start;i < end; i++)
	printf("%d,",a[i]);
	putchar(10);
	printf("其和为%d\n", max);
	return 0;
}
