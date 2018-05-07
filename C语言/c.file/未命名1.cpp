#include<stdio.h>
int main()
{
	FILE *fp;
	fp=fopen("text.01","w");
	fprintf(fp,"hello world!");
	fclose(fp);

	return 0;
}
