/*请在递归的框架下使用备忘录方法计算最长公共子序列的长度。
给定输入，其中序列1的内容为(注意==表示序列的边界)：
==OpenPR uses the BSD license. Its content is as follows:

Copyright (c) 2009-2015, Author: Xiao-Bo Jin
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
    Neither the name of the <ORGANIZATION> nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.==

序列2的内容为：==OpenPR uses the BSD license. Its content is as follows:

Copyright (c) 2009-2015, Author: Xiao-Bo Wang
All rights reserved and no other can modify them.

Retribution and use in source and binary forms, without modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, is list of conditions and the following disclaimer.
    binary form must reproduce the above copyright and there is no such right, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
    Nether the name of the <ORGANIZATION> nor the names of may be used to endorse or promote products derived from this prior written permission.==
*/
#include<stdio.h>

#include<string.h>

#define N 10000

void LCSLength(int m, int n,char *x, char *y);

int c[N][N];

int main()
{
	int i = 1, j = 1;
	char x[N];
	char y[N];
	while(x[i++] = getchar(),x[i-1] != '=') ;
	x[--i] = '\0';
	getchar();
	while(y[j++] = getchar(),y[j-1] != '=') ;
	y[--j] = '\0';


	LCSLength(i,j,x,y);
	
	
	
	return 0;
}
void LCSLength(int m, int n,char *x,char *y)
{
	int i, j;
	for(i = 1;i <= m;i++) c[i][0] = 0;
	for(j = 1;j <= n;j++) c[0][i] = 0;
	for(i = 1; i <= m;i++)
		for(j = 1;j <= n;j++){
			if(x[i] == y[j])
			{
				c[i][j] = c[i-1][j-1] + 1;
			}
			else if(c[i-1][j] >= c[i][j-1])
			{
				c[i][j] = c[i-1][j];
			}
			else 
			{
				c[i][j] = c[i][j-1];
			}
		}
		printf("%d\n", c[m][n]);
}

