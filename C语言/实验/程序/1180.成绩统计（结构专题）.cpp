#include<stdio.h>
	struct student
	{
		double num;
		char name[20];
		float chinese, math, english;
		float all;
	}; 
int main()
{

	struct student stu[100];
	int n, i, flag=0;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%lf%s %f%f%f", &stu[i].num, &stu[i].name, &stu[i].chinese, &stu[i].math, &stu[i].english);
		stu[i].all=stu[i].chinese+stu[i].math+stu[i].english;
	}
	for(i=1;i<n;i++)
	{
		if(stu[flag].all<stu[i].all)
		flag=i;
	}
	printf("%.0f %s %.0f %.0f %.0f", stu[flag].num, stu[flag].name, stu[flag].chinese, stu[flag].math, stu[flag].english);
	return 0;
}
