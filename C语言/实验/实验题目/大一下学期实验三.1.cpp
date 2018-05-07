/*大一下学期实验三.2*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	struct stu
	{
           int num;
           char b[20];
           int mathscore, chiscore,engscore;         
     }a[5];
	int i;
	double all, aver;
	if((fp=fopen("fp2.txt","w+"))==NULL)
	{
           printf("can not open this file!\n");
           exit(0);                                   
    }
	for(i=0;i<5;i++)
	{
		scanf("%d%s%d%d%d", &a[i].num,a[i].b, &a[i].mathscore,&a[i].chiscore,&a[i].engscore);
         fprintf(fp,"%d %s %d %d %d\n", a[i].num,a[i].b, a[i].mathscore,a[i].chiscore,a[i].engscore);                                      
    }
    fseek(fp,0,0);
    for(i=0;i<5;i++)
    {
        all=0;
        fscanf(fp,"%d%s%d%d%d",&a[i].num,a[i].b, &a[i].mathscore,&a[i].chiscore,&a[i].engscore);
        all=a[i].mathscore+a[i].chiscore+a[i].engscore;
        aver=all/3.0;
        printf("%d %s %d %d %d %f %f\n", a[i].num,a[i].b, a[i].mathscore,a[i].chiscore,a[i].engscore,all, aver);
    }
    fclose(fp);
scanf("%lf", all);
	return 0;
}
