#include<stdio.h>
int main()
{
	void mcopy(char *s, char *t, int m); 
	char ch[100], c[100];
	int m; 
	printf("������һ���ַ������Իس�������\n");
    gets(ch);
    printf("������ӵڼ�����ʼ���ƣ�\n");
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
