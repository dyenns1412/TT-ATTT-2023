#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
	int i;
	if (n < 2) return 0;
	for (i = 2; i <=n/2; i++)
	{
		if (n % i == 0) return 0;
	}
	return 1;
}

int main()
{
	int a, b, count = 0, sum = 0;
	scanf("%d%d", &a, &b);
	while (a==b || a>b || a<0 || b<0)
	{
		printf("Nhap lai A, B thoa man 0 <= A < B:\n");
		scanf("%d%d", &a, &b);
	}
	for (int i = a; i <= b; i++)
	{
		if (isPrime(i)) 
		{
			printf("%d ", i);
		    count++;
			sum += i;
		}
			
	}
	printf("\nC4: %d\n", count);
	printf("C5: %d\n", sum);

	return 0;
}