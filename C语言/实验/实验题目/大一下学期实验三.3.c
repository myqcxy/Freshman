
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
	for(i=0;;i++)
	{
		scanf("%d", &a[i].num);
		if(a[i].num==-1)
		break;
		scanf("%s%d%d%d",a[i].b, &a[i].mathscore,&a[i].chiscore,&a[i].engscore);
		
         fprintf(fp,"%d %s %d %d %d\n", a[i].num,a[i].b, a[i].mathscore,a[i].chiscore,a[i].engscore);                                      
    }
    fseek(fp,0,0);
    while(!feof(fp))
    {
        fscanf(fp,"%d%s%d%d%d",&a[i].num,a[i].b, &a[i].mathscore,&a[i].chiscore,&a[i].engscore);
        all=a[i].mathscore+a[i].chiscore+a[i].engscore;
        aver=all/3.0;
        printf("%d %s %d %d %d %f %f\n", a[i].num,a[i].b, a[i].mathscore,a[i].chiscore,a[i].engscore,all, aver);
    }
    if(fclose(fp))
    {
        printf("can not close this file!\n");
        exit(0);              
    }
scanf("%d", &i);
	return 0;
}
