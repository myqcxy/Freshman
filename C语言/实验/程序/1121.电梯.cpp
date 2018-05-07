#include<stdio.h>
int main()
{
	int down=0, up=0, time;
	int a[1000], i, n;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]); 
	}
	for(i=1;i<n;i++)
	{
		if(a[i]<a[i-1])
		{
			down+=(a[i-1]-a[i]);
	    }
		if(a[i]>a[i-1])
		{
			up+=(a[i]-a[i-1]);
	    }

	}
	time=down*4+(up+a[0])*6+n*5;
    printf("%d", time);
    
    return 0; 
}

