#include<stdio.h>

int isPrime(int n)
{
    if(n<=1) return 0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

int nhanBinhPhuongCoLap (int a, int k, int n)
{
    int b = 1;
    int A = a;
    if( k == 0)
        return b;
    else
    {
        if(k % 2 == 1)
            b = a;
        k /= 2;
        while(k != 0)
        {
            A = A*A % n;
            if(k % 2 == 1)
            {
                b = A*b %n;
            }
            k /= 2;
        }
    }
    return b;
}

int main()
{
    int a,k,n;
    scanf("%d %d %d", &a, &k, &n);

    int kq = nhanBinhPhuongCoLap(a,k,n);
    if(isPrime(kq))
    {
        printf("%d ^ %d mod %d = %d, la SNT", a, k,n,kq);
    } 
    else
    {
        printf("%d ^ %d mod %d = %d, khong la SNT", a, k,n,kq);
    }

    return 0;
}