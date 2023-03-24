#include<stdio.h>
#include<math.h>


int isPrime(int a)
{
    if (a<=1) return 0;
    for (int i = 2; i*i <=a; i++)
    {
        if( a % i == 0) return 0; 
    }
    return 1;
}

int GCD(int a, int b)
{
    int tmp;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int A[n];
    for(int i=0; i<=n;i++)
    {
        scanf("%d", &A[i]);
    }

    int count=0;
    for(int i=1; i<=n;i++)
    {
        for (int j= i+1; j<=n; j++)
        {
            int d = GCD(i,j);
            if (isPrime(d))
            {
                count ++;
                printf ("(%d, %d) ", A[i], A[j]);
            }

        }
    }
    printf ("\nC40: %d", count);
    return 0;
}