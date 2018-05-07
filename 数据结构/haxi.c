#include<stdio.h>
#define max 16
int hashtable[max];
int size=16;
int s=12;
int main()
{
	int i, j=0;
	int num[12]={19,14,23,1,68,20,84,27,55,11,10,79};
	int pos;
	int hash;
	for(i=0;i<max;i++) hashtable[i]=-1;
	while(j++<12)
	{
		hash=num[j]%13;
		pos=hash%size;
		while(hashtable[pos]!=-1)
		{
			hash++;
			pos=hash%size;
		}
		hashtable[pos]=num[j];
	}
	for(i=0;i<max;i++)
	 printf("%d,", hashtable[i]);
	 j=0;
	while(j++<12)
	{
		hash=num[j]%13;
		pos=hash%size;
		while(hashtable[pos]!=num[j])
		{
			s++;
			hash++;
			pos=hash%size;
		}
	}
	printf("\n%.2f\n", 1.0*s/12);
	int t,count=0;
	scanf("%d", &t);
	hash=t%13;
	pos=hash%size;
	while(hashtable[pos]!=t)
	{
		count++;
		if(count>size)break;
		s++;
		hash++;
		pos=hash%size;
	}
	if(hashtable[pos]!=t) printf("查找失败！\n");
	else printf("查找成功！\n");
	return 0;
}
