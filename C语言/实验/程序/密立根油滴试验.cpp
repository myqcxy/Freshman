#include<stdio.h>
#include<math.h>
int main()
{
	double t, u, q, e = 0.0, e1;
	int i = 15, n;
	while(i--)
	{
		printf("�������ѹ��u����ʱ�䣨s��\n");
		scanf("%lf%lf", &u,&t);
		t = (int)(pow(t*(1+0.02*sqrt(t)),1.5) + 0.5); 
		q = 1.02 / (u*t) * 100000;
		printf("q = %.2f   ", q);
		n = (int)((q / 1.6) + 0.5);
		printf("n = %d  ", n);
		e1 = q / n;  
		printf("e = %.2f  ",e1);
		e += e1;		
		putchar(10);
	}
	printf("ƽ������� = %.2f", e/15);
	
	return 0;
}
//�������͵������㷨�����ָ�� 
