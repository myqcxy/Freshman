#include <stdio.h>
main()
{float height=100.0,sum_height=100;
int i;
for(i=1;i<10;i++) {
height=height/2;
sum_height+=height*2;
}
printf("%fm\n",sum_height);
printf("%fm\n",height);
return 0;
}
