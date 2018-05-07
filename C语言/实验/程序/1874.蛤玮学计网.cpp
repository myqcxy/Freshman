#include <stdio.h>
#include <string.h>
int a,b,c,d;
char s[50];
int main() {
    int t;
    scanf("%d", &t);
    char e;
    while(t--)
    {
    	scanf("%s", s);
    	if (4==sscanf(s,"%d.%d.%d.%d%c",&a,&b,&c,&d, &e)) {
        if (0<=a && a<=255
         && 0<=b && b<=255
         && 0<=c && c<=255
         && 0<=d && d<=255) {
            printf("Yes\n",s);
        } else {
            printf("No\n",s);
        }
	    } else {
	        printf("No\n",s);
    }
	}
    
    return 0;
}
