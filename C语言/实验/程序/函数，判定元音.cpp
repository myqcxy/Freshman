#include<stdio.h>

int main()
{
	int vowel(char ch);
	char a;
	int i=0;
	a=getchar();
    while(a!='\n')
    {
    	if (vowel(a)==1)
    	i++;
    	a=getchar(); 
	}
	printf("%d", i);
	
	
	return 0;
}
int vowel(char ch)
{
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
	return 1;
	else
	return 0;
}
