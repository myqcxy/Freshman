/*¿ìËÙÅÅĞò*/ 
#include<stdio.h>
int partition(int *num,int low,int high);
void Qsort(int *num,int low, int high);
int main()
{
	int n, i;	
	int xier;
	int num[100];
	scanf("%d", &n);
	for(i=0;i<n;i++) scanf("%d", &num[i]);
	Qsort(num,0,n-1);
	for(i=0;i<n;i++) printf("%d,", num[i]);
	
	return 0;
}
int partition(int *num,int low,int high)
{
	int x;
	x=num[low];
	while(low<high)
	{
		while(high>low&&num[high]>=x) high--;		
		num[low]=num[high];
		
		while(high>low&&num[low]<=x) low++;		
		num[high]=num[low];
	}
	num[low]=x;
	return low;
}
void Qsort(int *num,int low, int high)
{
	if(low<high)
	{
		Qsort(num,partition(num,low,high)+1,high);
		Qsort(num,low,partition(num,low,high)-1);	
	}
	
} 
