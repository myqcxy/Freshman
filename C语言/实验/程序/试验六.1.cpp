#include<stdio.h>
int main()
{
	void sum_diff(float op1, float op2, float *psum, float *pdiff);
	float a, b, *sum, *diff;
	scanf("%f%f", &a, &b);
	sum_diff(a, b, sum, diff);
	printf("%.2f %.2f\n", *sum, *diff);
	
	
	return 0;
}
void sum_diff(float op1, float op2, float *psum, float *pdiff)
{
	*psum=op1+op2;
	*pdiff=op1-op2;
	
}
