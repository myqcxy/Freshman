#include<stdio.h>

#define N 50 

void Sum(int a[], int len_a, int sum[], int len_sum )//����� 
{
	int i;
	sum[0] = a[0];
	for( i = 1; i < len_a; i++)
		sum[i] = sum[i-1] + a[i];	
}
void maximumSubSequence(int a[], int len_a, int sum[], int len_sum, int *start, int *end, int* max)
{
	int i, j, k, sum1;
	*max = a[0];
	for(i = 0; i < len_a; i++)//ö�ٷ��������еĺ� 
		for( j = i; j < len_a; j++)
		{
			sum1 = sum[j] - sum[i] + a[i];
			if( sum1 > *max)//�ҳ������������в���������Լ���ʼ�±� 
			{
				*max = sum1;
				*start = i;
				*end = j;
			}
		}
}
int main()
{
	int a[]={23, -8, -29, -16, 46, -49, 46, 43, 
	44, 43, -10, -15, -20, 0, -38, 27, 
	15, -34, -12, -36, 19, 30, -49, 2, 
	24, -35, -1, 4, 7, -29, 12, -31, 
	-48, -33, -32, 4, 47, -25, -10, -28}; 
	int sum[N] ;
	int start, end, max;
	int i;
	Sum( a, sizeof(a)/sizeof(int), sum, N );
	maximumSubSequence(a, sizeof(a)/sizeof(int), sum, N, &start, &end, &max);
	printf("�����������Ϊ�ӵ�%d���%d��", start+1, end+1);
	printf("\n�ֱ��ǣ�\n");
	for( i = start;i <= end; i++)
	printf("%d,",a[i]);
	putchar(10);
	printf("���Ϊ%d\n", max);
	return 0;
}
