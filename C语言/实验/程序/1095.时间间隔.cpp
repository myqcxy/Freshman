#include<stdio.h>

int main()
{
	int HmsToS(int h, int m, int s);
	void PrintTime(int s);
	int p, h1,i=3, m1, q, s1, h2, m2, s2, w;
	
	
    while(scanf("%d:%d:%d%d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2)!=EOF)
    {
    	q=HmsToS(h1, m1, s1);
        p=HmsToS(h2, m2, s2);
        w=p-q;	
        PrintTime(w);
	}
		
	
    
	return 0;
}
int HmsToS(int h, int m, int s)
{
	int a;
	a=s+m*60+h*60*60;
	return a;
}
void PrintTime(int s)
{
	int h, m, n;
	h=s/3600;
	m=s%3600/60;
	n=s-h*3600-m*60;
	printf("%02d:%02d:%02d\n", h, m, n);
}
