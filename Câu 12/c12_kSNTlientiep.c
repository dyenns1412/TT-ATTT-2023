#include <stdio.h>
#include <math.h>
#define true 1
#define false 0

int isPrime(int n)
{
	if(n<2)
		return false;
	for(int i=2; i<=sqrt(n); i++)
	{
		if(n%i == 0)
			return false;
	}
	return true;
}

void solve(int n)
{
	int prime[n+1];
	for(int i=0; i<n+1; i++)
		prime[i] = 1;
	prime[0] = prime[1] = 0;
	for(int i=2; i<=n; i++)
	{
		if(prime[i])
		{
			for(int j=i*i; j<=n; j+=i)
				prime[j] = 0;
		}
	}
	
	int a[1000];
	int index=0;
	for(int i=2; i<=n; i++)
	{
		if(prime[i])
			a[index++] = i;
	}
	for(int i=0; i<index-3; i++)
	{
		int s = a[i] + a[i+1] + a[i+2] + a[i+3];
		if(s <= n && isPrime(s))
			printf("%d\n%d\n%d\n%d\n", a[i], a[i+1], a[i+2], a[i+3]);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	solve(n);

	return 0;
}

