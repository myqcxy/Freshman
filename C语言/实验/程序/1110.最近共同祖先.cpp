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
//���x==y, return x; 
//���x>y����x/2��y�Ĺ�ͬ����; 
//������x��y/2�Ĺ�ͬ����; 
}
