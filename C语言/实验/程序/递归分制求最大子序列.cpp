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
	for(i = mid;i >= start;i--)
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
	int a[123] = {-49,34,14,-34,23,17,-19,-49,36,37,
-37,37,-3,6,-42,-19,-22,48,20,-15,
-2,-32,20,-35,-3,25,-46,9,15,32,
-41,-38,20,-29,-3,-29,-8,47,41,-44,
12,39,40,22,-20,-21,-14,-40,-32,-40,
-25,-19,-28,37,-21,26,-33,-41,2,-11,
-11,20,-26,-21,-1,4,10,0,25,-45,
41,45,40,-33,2,-21,-30,-41,-12,19,
0,-22,-2,2,-27,19,31,14,25,17,
-7,-13,-12,-23,42,46,-27,4,-21,13,
-25,21,-47,24,35,-1,31,-14,-42,6,
10,46,45,21,-43,-26,-46,-25,22,22,
20,-13,-1};

	printf("%d\n", maxSort(a,0,122));
	
	
	
	return 0;
}

