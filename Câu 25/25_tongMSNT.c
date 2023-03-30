#include <stdio.h>
#include <math.h>
#define true 1
#define false 0
#define MAX 10001

int isPrime(int n)
{
	if(n<2)
		return false;
	for(int i=2; i<=sqrt(n); i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

void findPrime (int n, int m, int prime[], int len, int a[], int res)
{
	if (n==0 && m==0)  
    {
        for(int i=res-1; i>=0; i--)	
			printf("%5d", a[i]);	
		printf("\n");
        return;
    }
    if (n == 0 || m == 0)
    	return;
	
	for(int i=0; i<len ; i++)
	{	
		if(n >= prime[i])
		{
			a[res] = prime[i];
			findPrime(n - prime[i], m - 1, prime, i, a, res + 1);
		}
	}
}

int main()
{
	int N, M;
	printf("Nhap N = ");
	scanf("%d", &N);
	printf("Nhap so luong so nguyen to M = ");
	scanf("%d", &M);
	
	int prime[MAX], len=0;
	for(int i=2; i<=N; i++)
	{
		if(isPrime(i))
			prime[len++] = i;
	}
	
	int a[MAX];
	findPrime(N, M, prime, len, a, 0);

	return 0;
}

