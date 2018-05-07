#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int bToD(char str[]); 
	char a[32], b[32], c[32];
	int x, y, z, t;
	scanf("%s%s%s", a, b, c);
	x=bToD(a);
	y=bToD(b);
	z=bToD(c);
	if(x>y) {t=x;x=y;y=t;}
	if(x>z) {t=x;x=z;z=t;}
	if(y>z) {t=y;y=z;z=t;} 
	printf("%d %d %d\n", x, y, z);
	
	
	return 0;
}
int bToD(char str[]) 
{
	int i, a=strlen(str)-1;
	int  b=0;
	for(i=0;a>=0;i++)
	{
		b+=(str[i]-'0')*pow(2,a);
		a--;
	}	
	return b;
//函数返回二进制数str对应十进制整数 
} 
