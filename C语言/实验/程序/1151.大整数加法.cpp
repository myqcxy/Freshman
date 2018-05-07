#include <stdio.h>
#include <string.h>
int main() 
{
	void strrevs(char *str); 
    int n;
    char a[1001], b[1001], c[1002];
    scanf("%d", &n);
    int i, j;
    for (i = 0; i < n; ++i) {
        scanf("%s %s", a, b);
        memset(c, '0', 1002);
        strrevs(a);
        strrevs(b);
        int lengtha = strlen(a);
        int lengthb = strlen(b);
        if (lengtha > lengthb)
		{
            for (j = 0; b[j] != '\0'; ++j) 
			{
                char value = c[j] - '0' + a[j] - '0' + b[j] - '0';
                if (value >= 10) 
				{
                    ++c[j + 1];
                    value -= 10;
                }
                c[j] = value + '0';
            }
            for (; a[j] != '\0'; ++j) 
			{
                char value = c[j] - '0' + a[j] - '0';
                if (value >= 10) 
				{
                    ++c[j + 1];
                    value -= 10;
                }
                c[j] = value + '0';
            }
        } 
		else 
		{
            for (j = 0; a[j] != '\0'; ++j) 
			{
                char value = c[j] - '0' + a[j] - '0' + b[j] - '0';
                if (value >= 10) 
				{
                    ++c[j + 1];
                    value -= 10;
                }
                c[j] = value + '0';
            }
            for (; b[j] != '\0'; ++j) 
			{
                char value = c[j] - '0' + b[j] - '0';
                if (value >= 10) 
				{
                    ++c[j + 1];
                    value -= 10;
                }
                c[j] = value + '0';
            }
        }
        if (c[j] != '0')
            c[j + 1] = '\0';
        else
            c[j] = '\0';
        strrevs(c);
        printf("%s\n", c);
    }
    return 0;
}
void strrevs(char *str)
 {
    int length = strlen(str);
    char * head = str;
    char * tail = str + length - 1;
    char tmp;
    while (head < tail)
	 {
        tmp = *head;
        *head = *tail;
        *tail = tmp;
        ++head;--tail;
    }
}
