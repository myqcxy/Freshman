#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{	
	time_t rawtime;	//time_tʱ����	
//	struct tm *timeinfo;	
	time(&rawtime);	//��ȡʱ��	
//	timeinfo=localtime(&rawtime); //תΪ����ʱ�䣬tm ʱ��ṹ
//	int day=timeinfo->tm_year;
//	printf("%d\n",day);
	printf("��ǰϵͳʱ��Ϊ��%d\n",rawtime);
//	printf("��ǰϵͳʱ��Ϊ��%s\n",asctime(timeinfo));//asctime()  תΪ��׼ASCIIʱ���ʽ	
	system("pause");	
	printf("tsystem(\"paus\")\n");//��Ҫ����ת���ַ�\	
	return 0;
}
