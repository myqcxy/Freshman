#include<stdio.h>

int  maxSort(int a[], int start,int end)
{
	if(start == end)
	if(a[start] > 0)
	return a[start];
	else return 0;
	int mid = (start + end) / 2;
	int leftMax,rightMax;
	 leftMax = maxSort(a,start,mid);
 rightMax = maxSort(a,mid+1,end);
	int i;
	int leftSum = 0, maxLeftSum = 0;	
	int rightSum = 0, maxRightSum = 0;
	leftSum = 0; maxLeftSum = 0;	
    rightSum = 0; maxRightSum = 0;	
	for(i = start;i <= mid;i++)
	{
		leftSum += a[i];
		if(leftSum > maxLeftSum)
			maxLeftSum = leftSum;
	}
	for(i = mid + 1;i <= end;i++)
	{
		rightSum += a[i];
		if(rightSum > maxRightSum)
			maxRightSum = rightSum;
	}
	if(rightMax > leftMax && rightMax > (maxLeftSum + maxRightSum))
	return rightMax;
	else if(leftMax > rightMax && leftMax > (maxLeftSum + maxRightSum))
	return leftMax;
	else return maxLeftSum + maxRightSum;
}

int main()
{
	int a[40] = {23,-8,-29,-16,46,-49,46,43,
44,43,-10,-15,-20,0,-38,27,
15,-34,-12,-36,19,30,-49,2,
24,-35,-1,4,7,-29,12,-31,
-48,-33,-32,4,47,-25,-10,-28};

	printf("%d\n", maxSort(a,0,39));
	
	
	
	return 0;
}

