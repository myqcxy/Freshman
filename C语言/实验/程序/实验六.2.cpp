/*2. ����10��������������a��
������һ������x��������a�в���x�����ҵ��������Ӧ���±꣬
������ʾ"Not found"��Ҫ����͵��ú���seach(int list[]��int n��int x)��
������list�в���Ԫ��x�����ҵ��򷵻���Ӧ���±꣬���򷵻�-1��
����n��������list��Ԫ�ص��������Ա�д��Ӧ����*/ 
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
