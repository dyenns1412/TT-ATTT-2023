#include<stdio.h>
#include<math.h>

int isPrime(int n)
{
	if (n < 2) return 0;
	for (int i = 2; i <=n/2; i++)
	{
		if (n % i == 0) return 0;
	}
	return 1;
}

int main()
{
    int a,b;
    scanf("%d%d", &a, &b);
    
    int sum=0;
    for(int i=a;i<=b;i++)
    {
        if(isPrime(i)==1)
        {
            sum+=i;
        }
    }
    printf("Sum = %d\n", sum);
    if(isPrime(sum)==1) printf("YES");
    else printf("NO");

    return 0;
}

