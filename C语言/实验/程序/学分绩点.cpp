#include <stdio.h>
#include <stdlib.h>
int main()
{double y;
double a,b,c,n,d,x,e;
x=d=0;
printf("�����ܵĿ�Ŀ��\n");
scanf("%lf",&n);
while(n--)
{ printf("����ÿ�ѧ�ּ�������\n");
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
printf("��ļ���Ϊ��\n");
printf("%.2f",y);
return 0;
}
