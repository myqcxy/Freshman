/*3. 输入一个字符串，将该字符串中从第m个字符开始的
全部字符复制成另一个字符串（不能使用系统库函数提供
的strcpy（）函数）。m由用户输入，值小于字符串的长度。要求
编写一个函数mcopy（char *s，char *t，int m）来完成。*/ 
#include<stdio.h>
int main()
{
	void mcopy(char *s, char *t, int m); 
	char ch[100], a, c[100], i=0;
	int m; 
	printf("请输入一个字符串，以回车结束：\n");
	gets(ch); 
    printf("请输入从第几个开始复制：\n");
	scanf("%d", &m);
	mcopy(ch, c, m-1); 

    return 0; 
}
void mcopy(char *s, char *t, int m) 
{
	int i, j=0;
	for(i=m;*(s+i)!='\0';i++)
	{
		*(t+j)=*(s+i);
		j++; 
	}
	puts(t); 
} 
