#include <stdio.h>
#include<math.h>

int isPrime(int n)
{
    int i;
    if(n<=1) return 0;
    for (i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

int main ()
{
    int n,i;
    printf("Nhap n=");
    scanf("%d",&n);
    for (i=2;i<=(n-2);i++)
    {
        if(isPrime(i)==1&&isPrime(i+2)==1) printf("%d\t%d\n",i,i+2);
    }
}
