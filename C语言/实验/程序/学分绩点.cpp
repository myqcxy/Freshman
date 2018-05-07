#include <stdio.h>
#include <stdlib.h>
int main()
{double y;
double a,b,c,n,d,x,e;
x=d=0;
printf("输入总的科目：\n");
scanf("%lf",&n);
while(n--)
{ printf("输入该科学分及分数：\n");
    scanf("%lf%lf",&a,&b);
   if(b<60)
    e=0;
   else
    e=(b-50)/10*a;
        x=x+a;
   c=e;
        d=d+c;
}
y=1.0*d/x;
printf("你的绩点为：\n");
printf("%.2f",y);
return 0;
}
