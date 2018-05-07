#include<stdio.h>
int main()
{
	void mcopy(char *s, char *t, int m); 
	char ch[100], c[100];
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
	for(i=0;i<j;i++)
	{
		printf("%c", *(t+i));
	}
}
