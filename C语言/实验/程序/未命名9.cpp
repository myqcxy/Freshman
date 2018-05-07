#include <stdio.h>
int main(void)
{
    int t,i,j;
    double n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lf",&n);
        for(j=1;j<=n;j++)
        {
            if(j%7==0||j%10==7||j%100/10==7||j%1000/100==7||j%10000/1000==7||j%100000/10000==7)
                printf("%d ",j);
        }
        printf("\n");
    }
    return 0;
}
