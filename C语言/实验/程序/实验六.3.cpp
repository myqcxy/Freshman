/*3. ����һ���ַ����������ַ����дӵ�m���ַ���ʼ��
ȫ���ַ����Ƴ���һ���ַ���������ʹ��ϵͳ�⺯���ṩ
��strcpy������������m���û����룬ֵС���ַ����ĳ��ȡ�Ҫ��
��дһ������mcopy��char *s��char *t��int m������ɡ�*/ 
#include<stdio.h>
int main()
{
	void mcopy(char *s, char *t, int m); 
	char ch[100], a, c[100], i=0;
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
	puts(t); 
} 
