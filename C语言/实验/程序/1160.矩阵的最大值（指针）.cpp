#include<stdio.h>
int main()
{
	void FindMax(int p[][3], int m, int n, int *pRow, int *pCol);
	int a[2][3], j, i, Row, Col;
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	FindMax(a, 2, 3, &Row, &Col);
	printf("%d %d %d", a[Row][Col], Row, Col);
	
	return 0;
}
void FindMax(int p[][3], int m, int n, int *pRow, int *pCol)
{
	int max=p[0][0], i, j;
	*pRow=0;
	*pCol=0;
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==0&&j==0)
			{
				continue;
			}
			if(p[i][j]>max)
			{
				max=p[i][j];
				*pRow=i;
				*pCol=j;
			}
		}
	}
	
	
 } 
