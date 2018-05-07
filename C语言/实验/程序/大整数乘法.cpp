/*����123456789�����ظ�5�ι���45λ������A��ͬʱ�ظ�987654321��
�����ظ�5�ι���45λ������B������ʵ�ִ������˷�A*B.*/
#include<stdio.h>
#include<string.h>
#define N 46

int  multiplication(char A[], int len_A,char B[], int len_B,char C[],int len_C)
{
	int i, j, k = 0, t;
	int value;
	memset(C,'0',len_C);
	for(i = 0;i < len_C;i++) C[i] = '0';
	for(j = len_B - 2,t = 0;j >= 0;j--,t++)
	{
		for(i = len_A - 2,k = t;i >= 0;i--,k++)
		{
			value =C[k] - '0' + (A[i] - '0') * (B[j] - '0');
			if(value > 9)
			{
				C[k+1] = C[k+1]+value / 10;	
				value %= 10;		
			}

				C[k] = value + '0';
		}
	}
	
	return k;
}
int main()
{
	char A[N], B[N], C[2*N];
	int i, j;
	for(i = 1, j = 0;i < 50;i++)
		if(i % 10)
			A[j++] = i % 10 + '0';
	A[j] = '\0';
	for(i = 49, j = 0;i > 0;i--)
		if(i % 10)
			B[j++] = i % 10 + '0';
	B[j] = '\0';
	putchar(10);

	j = multiplication(A, N,B, N, C,2 * N);
	for(i = j; i >= 0;i--)
	 printf("%c", C[i]);
	 putchar(10);

	return 0;
}
