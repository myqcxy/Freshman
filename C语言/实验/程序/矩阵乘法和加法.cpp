/*矩阵乘法和加法：已知A，求解下列表达式的值，A^0 + A^1 + A^2
+ A^3 + A^4  + A^5, 其中A为9行9列矩阵，如下：
1 2 3 4 5 6 7 8 9；
2 3 4 5 6 7 8 9 1；
3 4 5 6 7 8 9 1 2；
.
.
.
9 1 2 3 4 5 6 7 8;*/
#include<stdio.h> 
int main()
{
	int a[9][9] = {{1,2,3,4,5,6,7,8,9},{2,3,4,5,6,7,8,9,1},{3,4,5,6,7,8,9,1,2},
				{4,5,6,7,8,9,1,2,3},{5,6,7,8,9,1,2,3,4},{6,7,8,9,1,2,3,4,5},
				{7,8,9,1,2,3,4,5,6},{8,9,1,2,3,4,5,6,7},{9,1,2,3,4,5,6,7,8}};
	int i, j, k, t, sum[9][9], pow1[9][9],pow2[9][9];
	for(i = 0;i < 9;i++)
		for(j = 0;j < 9;j++)
		{
			sum[i][j] = 1 + a[i][j];
			pow1[i][j] = 0;
			pow2[i][j] = 0;
		}
		for(i = 0;i < 9;i++)
			for(j = 0;j < 9;j++)
				for(k = 0;k < 9;k++)
				{
					pow1[i][j] += a[i][k] * a[k][j];
					sum[i][j] += pow1[i][j];
				}
		for(i = 0;i < 9;i++)
			for(j = 0;j < 9;j++)
				for(k = 0;k < 9;k++)
				{
					pow2[i][j] += pow1[i][k] * a[k][j];
					sum[i][j] += pow2[i][j];
				}
		for(i = 0;i < 9;i++)
		for(j = 0;j < 9;j++)
			pow1[i][j] = 0;
		for(i = 0;i < 9;i++)
			for(j = 0;j < 9;j++)
				for(k = 0;k < 9;k++)
				{
					pow1[i][j] += pow2[i][k] * a[k][j];
					sum[i][j] += pow1[i][j];
				}
		for(i = 0;i < 9;i++)
		for(j = 0;j < 9;j++)
			pow2[i][j] = 0;
		for(i = 0;i < 9;i++)
			for(j = 0;j < 9;j++)
				for(k = 0;k < 9;k++)
				{
					pow2[i][j] += pow1[i][k] * a[k][j];
					sum[i][j] += pow2[i][j];
				}							
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
			printf("%10d", sum[i][j]);
		putchar(10);
	}
	
	
	
	
	return 0;
}
