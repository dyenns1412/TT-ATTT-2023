#include<stdio.h>
#include<math.h>

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
int sieuSNT(int n)
{
    int count=0;
    for(int i=1;i<n;i++)
    {
        if(isPrime(i)==1)
        {
            count++;
        }
    }
    if(isPrime(count)==1) return 1;
    return 0;
}

int main()
{
    int count=0;
    int a,b;
    scanf("%d%d", &a, &b);
    for(int i=a;i<=b;i++){
        if(sieuSNT(i)==1)
        {
           count++;
        }
    }
    printf("%d",count);
    
    return 0;
}