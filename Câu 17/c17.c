#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n)
{
    if (n<2) return 0;
    for (int i=2; i<=sqrt(n); i++)
    {
        if (n%i==0) return 0;
    }
    return 1;
}

int main()
{
    int a, b, c;
    printf ("Nhap A: ");
    scanf("%d", &a);
    printf ("Nhap B: ");
    scanf("%d", &b);
    printf ("Nhap C: ");
    scanf("%d", &c);
    for (int i=1; ; i++)
    {
        int gt = a*i*i+b*i+c;
        if (isPrime(gt)==1)
        {
            printf("Xmin = %d", i);
            break;
        }
    }
}
