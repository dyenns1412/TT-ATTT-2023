#include<stdio.h>
#include<math.h>

int isPrime(int x)
{
	if(x<2)
		return 0;
	for(int i=2; i<=sqrt(x); i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}

int reverse(int x)
{
    int r, rev=0;
    while(x>0)
    {
        r = x % 10;
        rev = rev * 10 + r;
        x = x/10;
    }
    return rev;
}

int main()
{
    int n;
	scanf("%d", &n);
	int check = 0;
	for(int i=0; i<n; i++)
	{
		if(isPrime(i) && isPrime(reverse(i)))	
		{
			printf("%d\n", i);
			check = 1;
		}
	}
	if(check==0) printf("Khong ton tai so Erimp nho hon %d",n);  
	return 0;

}