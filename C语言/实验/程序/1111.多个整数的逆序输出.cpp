#include<stdio.h>
int main()
{
	void inverse(int n); 
	int n;
	scanf("%d", &n); 
	inverse(n);
	
	return 0;
}
void inverse(int n)
{
	int num;
    if(n>=1)
    {
		scanf("%d", &num);
		inverse(n-1);
        printf("%d ", num);
    }
}
