#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{	
	time_t rawtime;	//time_t时间类	
//	struct tm *timeinfo;	
	time(&rawtime);	//获取时间	
//	timeinfo=localtime(&rawtime); //转为当地时间，tm 时间结构
//	int day=timeinfo->tm_year;
//	printf("%d\n",day);
	printf("当前系统时间为：%d\n",rawtime);
//	printf("当前系统时间为：%s\n",asctime(timeinfo));//asctime()  转为标准ASCII时间格式	
	system("pause");	
	printf("tsystem(\"paus\")\n");//需要输入转意字符\	
	return 0;
}
