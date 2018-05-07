int prime(int n)
{
	int m, i;
	m=(int)sqrt(n);
	if(n==1) return 0;
	else for(i=2;i<=m;i++)
	{
		if(n%i==0) return 0;
	}
	return 1;
}
