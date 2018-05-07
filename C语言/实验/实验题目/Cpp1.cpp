#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int ID;
	char name[10];
	int math,english,chinese;
	int all;
	double ave;
}STUDENT;
int main()
{
	STUDENT stu[5],stu1[5];
	int i;
	FILE *fp;
	if((fp=fopen("f3.txt","w+"))==NULL)
	{
		printf("can not open this file\n");
		exit(0);
	}

	for(i=1;i<=5;i++)
	{
		printf("请输入第%d个学生的学号、姓名、数学分、英语分、语文分：\n",i);
		scanf("%d%s%d%d%d",&stu[i-1].ID,stu[i-1].name,&stu[i-1].math,&stu[i-1].english,&stu[i-1].chinese);
		fprintf(fp,"%d%s%d%d%d\n",stu[i-1].ID,stu[i-1].name,stu[i-1].math,stu[i-1].english,stu[i-1].chinese);
	}

	fseek(fp,0,0);

	for(i=1;i<=5;i++)
	{
		fscanf(fp,"%d%s%d%d%d",&stu1[i-1].ID,stu1[i-1].name,&stu1[i-1].math,&stu1[i-1].english,&stu1[i-1].chinese);
	}
	for(i=0;i<5;i++)
	{
		printf("第%d个学生的总成绩、平均成绩:\n",i+1);
		stu1[i].all=stu1[i].math+stu1[i].english+stu1[i].chinese;

		stu1[i].ave=stu1[i].all/3.0;

		printf("%d %f\n",stu1[i].all,stu1[i].ave);
	}
	fclose(fp);
	return 0;
}
