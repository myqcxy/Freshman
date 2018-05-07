#include<stdio.h>
int main(){
	int a[102][102];
	int n,i,j,k=0,t=0;
	int x,y;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++) scanf("%d",&a[i][j]);
    
    int sum;
    for(i=0;i<n;i++)
    {
       sum=0;
	   for(j=0;j<n;j++) sum+=a[i][j];
	   if(sum%2==1) {k++;x=i;}
    }
    
    for(j=0;j<n;j++)
    {
       sum=0;
	   for(i=0;i<n;i++) sum+=a[i][j];
	   if(sum%2==1) {t++;y=j;}
    }
	
    if(k==1 && t==1)            printf("Change bit(%d,%d)",x,y);
    else if(k==0 && t==0)       printf("OK");
    else                        printf("Corrupt");
	return 0;
}
