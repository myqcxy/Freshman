#include<stdio.h>
int main()
{
	int common(int x, int y); 
	int x, y;
	scanf("%d%d", &x, &y);
	printf("%d\n", common(x,y));
	return 0;
}
int common(int x, int y) 
{ 
	if(x==y) return x;
	if(x>y)
	{
		return common(x/2,y);
	}
	else return common(x,y/2);
//如果x==y, return x; 
//如果x>y，求x/2与y的共同祖先; 
//否则，求x与y/2的共同祖先; 
}
