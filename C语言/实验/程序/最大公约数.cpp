/*5.6.[拓展题目]编写程序，输入两个正整数m和n，求其最大公约数和最小公倍数。
输入样例：4  6
输出样例：2  12
输入样例：7  8
输出样例：1  56
输入样例：8  24
输出样例：8  24
*/
#include<stdio.h>
int main()
{
	int m, n, i, a, b;
	scanf("%d%d", &m, &n);
    for(i=2;i<=m;i++)
    {
    	if(m%i==0&&n%i==0)
    	a=i; 
	}
	b=m*n/a;
	printf("%d %d", a, b);
	return 0;
 } 
