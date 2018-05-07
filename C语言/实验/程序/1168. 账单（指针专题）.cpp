#include<stdio.h>
#include<string.h>

int main()
{
	int ncase;
	scanf("%d", &ncase);
	char str1[201], str2[20];
	while(ncase--)
	{
		int n, i=0, len, flge;
		float sum=0, num;
		scanf("%d", &n);
		getchar();
		while(n--)
		{
			gets(str1);
			memset(str2,0,sizeof(str2)); 
			len=strlen(str1);
			for(i=len-1;i>0;i--){
                if(str1[i]==' '){
                    flge=i;break;}}
            strcpy(str2,str1+flge+1);
            sscanf(str2,"%f", &num);
            sum+=num;
		}
		printf("%.1f\n", sum);
	}
	return 0;
}

