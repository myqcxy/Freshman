#include<stdio.h>
int main()
{
	struct student
	{
		char name[30];
		int ave, ban, lun;
		char ganbu, xibu;
		int qian;	
	}a[10], b;
	int n, i, sum=0;
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		a[i].qian=0;
		scanf("%s%d%d%*c%c%*c%c%d", a[i].name, &a[i].ave,
		 &a[i].ban, &a[i].ganbu, &a[i].xibu, &a[i].lun);
		 if(a[i].lun>=1&&a[i].ave>80) a[i].qian+=8000;
		 if(a[i].ave>85&&a[i].ban>80) a[i].qian+=4000;
		 if(a[i].ave>90) a[i].qian+=2000;
		 if(a[i].ave>85&&a[i].xibu=='Y') a[i].qian+=1000;
		 if(a[i].ban>80&&a[i].ganbu=='Y') a[i].qian+=850;
		 sum+=a[i].qian;
	}
	b=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i].qian>b.qian) b=a[i];
	}
	printf("%s\n%d\n%d\n", b.name, b.qian, sum);
	
	return 0;
}
