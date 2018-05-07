#include<stdio.h>
#include<string.h>
char a1[10000], b1[10000];

int main()
{
int to(char ch);
	int ii, a, b, t=1;
	while(scanf("%s%s", a1, b1)!=EOF)
	{
//		min=(strlen(a1)>=)?strlen(b1):strlen(a1);
//		printf("%d,", min);
		for(ii=0;ii<strlen(b1);ii++)
		{
			t=1;
			a=to(a1[ii]);
			b=to(b1[ii]);
			if(a1[ii]=='\0') a=0;
			if(a<b) 
			{
				printf("YES\n");
				t=0;
				break;
			}
			else if(a>b) 
			{
				printf("NO\n");
				t=0;
				break;
			}
			else 
			continue;
		}
		if(t) printf("NO\n");
	}
	
	return 0;
}
int to(char ch)
{
	if(ch=='A') return 1;
	if(ch=='a') return 2;
	if(ch=='B') return 3;
	if(ch=='b') return 4;
	if(ch=='C') return 5;
	if(ch=='c') return 6;
	if(ch=='D') return 7;
	if(ch=='d') return 8;
	if(ch=='E') return 9;
	if(ch=='e') return 10;
	if(ch=='F') return 11;
	if(ch=='f') return 12;
	if(ch=='G') return 13;
	if(ch=='g') return 14;
	if(ch=='H') return 15;
	if(ch=='h') return 16;
	if(ch=='I') return 17;
	if(ch=='i') return 18;
	if(ch=='J') return 19;
	if(ch=='j') return 20;
	if(ch=='K') return 21;
	if(ch=='k') return 22;
	if(ch=='L') return 23;
	if(ch=='l') return 24;
	if(ch=='M') return 25;
	if(ch=='m') return 26;
	if(ch=='N') return 27;
	if(ch=='n') return 28;
	if(ch=='O') return 29;
	if(ch=='o') return 30;
	if(ch=='P') return 31;
	if(ch=='p') return 32;
	if(ch=='Q') return 33;
	if(ch=='q') return 34;
	if(ch=='R') return 35;
	if(ch=='r') return 36;
	if(ch=='S') return 37;
	if(ch=='s') return 38;
	if(ch=='T') return 39;
	if(ch=='t') return 40;
	if(ch=='U') return 41;
	if(ch=='u') return 42;
	if(ch=='V') return 43;
	if(ch=='v') return 44;
	if(ch=='W') return 45;
	if(ch=='w') return 46;
	if(ch=='X') return 47;
	if(ch=='x') return 48;
	if(ch=='Y') return 49;
	if(ch=='y') return 50;
	if(ch=='Z') return 51;
	if(ch=='z') return 52;	
}
