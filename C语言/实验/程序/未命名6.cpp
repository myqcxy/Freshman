#include <string.h>
#include <stdio.h>

int main(void)
 {
    char string[15];
    char *ptr, c = 'i';

    strcpy(string, "This is a string");
    ptr = strchr(string, c);
    if (ptr)
       printf("The character %c is at position: %s\n", c, ptr);
    else
       printf("The character was not found\n");
    return 0;
 }


