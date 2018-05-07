#include<stdio.h>
int main()
{
    int t,s;
    int a[4]={0};//四个方向行驶的距离 0北 1西 2南 3东
    int ss=0;//现在的方向
    int tt=0;//最后一次转向的时间
    while(scanf("%d%d",&t,&s)!=EOF)
    {
        a[ss]+=(t-tt)*10;
        tt=t;
        if(s==1) ss=(ss+1)%4;
        if(s==2) ss=(ss+3)%4;
        if(s==3) break;
    }
    printf("%d %d\n",a[3]-a[1],a[0]-a[2]);
    return 0;
}	
