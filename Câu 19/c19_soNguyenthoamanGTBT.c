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
    int a, b, c, m, l;
    printf ("Nhap m, l (m<l): ");
    scanf("%d%d", &m, &l);
    printf ("Nhap A: ");
    scanf("%d", &a);
    printf ("Nhap B: ");
    scanf("%d", &b);
    printf ("Nhap C: ");
    scanf("%d", &c);
    for (int i=m; i<=l; i++)
    {
        int gt = a*i*i+b*i+c;
        if (isPrime(gt)==1)
        {
            printf("x = %d\n", i);
        }
    }
}
