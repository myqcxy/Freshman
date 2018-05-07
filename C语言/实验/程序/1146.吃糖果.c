/*Description
HOHO，终于从Speakless手上赢走了所有的糖果，是Gardon吃糖果时有个特殊的癖好，
就是不喜欢连续两次吃一样的糖果，喜欢先吃一颗A种类的糖果，下一次换一种口味，
吃一颗B种类的糖果，这样；可是Gardon不知道是否存在一种吃糖果的顺序使得他能把所有糖果都吃完
？请你写个程序帮忙计算一下。 
Input
第一行有一个整数T，接下来T组数据，每组数据占2行，第一行是一个整数N（0 < N <= 1000000)，
表示糖果的种类。第二行是N个数，表示每种糖果的数目Mi(0 < Mi <= 1000000)。 
Output
对于每组数据，输出一行，包含一个"Yes"或者"No"。 
*/
#include<stdio.h>
int a[1000000];
int main()
{
	int i, T, n, t , sum;
	scanf("%d", &T);
	while(T--)
	{
		sum=0;
		scanf("%d", &n);
		for(i=0;i<n;i++) scanf("%d", &a[i]);
		t=a[0];
		for(i=1;i<n;i++)
		{
			if(t>a[i])
				sum+=a[i];
			else 
			{
				sum+=t;
				t=a[i];
			}
		}
		if(t<=sum+1)
		{
			printf("Yes\n");
		}
		else printf("No\n");					
	}

	return 0;
}