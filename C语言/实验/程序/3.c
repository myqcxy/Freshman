#include<math.h>
int prime(int b[],int n)
{
	int j,k,m,count=0;

	for(j=0;j<n;j++)
	{
		m=(int)sqrt(b[j]);
		for(k=2;k<=m;k++)
		{
			if(b[j]%k==0)
				break;
			if(k==m)
				count++;
		}
	}
	return count;
}
