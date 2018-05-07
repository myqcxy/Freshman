/*2. 输入10个整数存入数组a，
再输入一个整数x，在数组a中查找x，若找到则输出相应的下标，
否则显示"Not found"。要求定义和调用函数seach(int list[]，int n，int x)，
在数组list中查找元素x，若找到则返回相应的下标，否则返回-1，
参数n代表数组list中元素的数量。试编写相应程序。*/ 
#include<stdio.h>
int main()
{
	int seach(int list[], int n, int x); 
    int i, a[10], x;
    printf("please input ten integers:\n"); 
    for(i=0;i<10;i++)
	{
		scanf("%d", a+i); 
	} 
	printf("please input the integer of your find:\n"); 
	scanf("%d", &x); 
	if(seach(a, 10, x)!=-1)
	{
		printf("your answer is:%d\n", seach(a, 10, x)); 
	} 
	else
	{
		printf("Not found!\n"); 
	} 

    return 0; 
} 
int seach(int list[], int n, int x)
{
	int i; 
	for(i=0;i<n;i++)
	{
		if(*(list+i)==x)
		{ 
		    return i;
		    break; 
		} 
	} 
	if(i<n)
	{
		return i; 
	} 
	else
	{ 
	    return -1; 
	} 
} 
