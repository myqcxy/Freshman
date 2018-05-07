#include<stdio.h>
struct IP
{
    int a;
    char q1;
    int b;
    char q2;
    int c;
    char q3;
    int d;
}s;
void yesno()
{

		scanf("%d%c%d%c%d%c%d%*c",&s.a,&s.q1,&s.b,&s.q2,&s.c,&s.q3,&s.d);
    if(s.a<256&&s.a>=0&&s.b<256&&s.b>=0&&s.c<256&&s.c>=0&&s.d<256&&s.d>=0)
    {
        if(s.q1=='.'&&s.q1=='.'&&s.q1=='.')printf("Yes\n");
        else printf("No\n"); 
    }
    else printf("No\n");
	 
    
}
 
main()
{
    int i;
    scanf("%d", &i);
    while(i--)
    {
    	yesno();
	}
}
