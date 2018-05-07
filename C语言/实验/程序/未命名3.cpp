#include<stdio.h>
void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
int main()
{
	int n;
	int a[200];
	scanf("%d", &n);
	for(int i = 0;i < n;i++)	
		scanf("%d", &a[i]);
	for(int i = 0;i<n;i++)
		for(int j = i+1;j<n;j++)
			if(a[i] > a[j])
				swap(a,i,j);
	for(int i = 0;i < n;i++)
		printf("%d ", a[i]);
	return 0;
} 
