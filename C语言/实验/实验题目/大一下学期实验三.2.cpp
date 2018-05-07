#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    double a;
    if((fp=fopen("f1.txt","w"))==NULL)
    {
        printf("can not open this file!\n");
        exit(0);                                  
    }
    while(scanf("%lf", &a))
    {
        if(a==-1) break;
        else fprintf(fp,"%lf\n",a);
    }
    if(fclose(fp))
    {
        printf("can not close this file!\n");
        exit(0);              
    }
    
    return 0;    
}
