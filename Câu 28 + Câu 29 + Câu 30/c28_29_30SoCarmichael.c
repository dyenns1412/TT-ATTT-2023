#include<stdio.h>
#include <stdlib.h>
#include<time.h>
// so carmichael la hop so nguyen thoa man b^(n-1) mod n =1 voi 1<=b<=n-1 va gcd(b,n)=1
int isPrime(int n)
{
    if(n<=1) return 0;
    for(int i=2; i*i<=n;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

int GCD(long long int a, long long int b)
{
    int tmp;
    while(b!=0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
}
long long int nhanBinhPhuongCoLap(long long int a, long long int k, long long int n)
{
    long long int b=1;
    long long int A=a;
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
int isCarmichael(int n)
{
    if(n <= 3 )
        return 0;

    srand(time(NULL)); // srand(time(NULL)); // thiết lập seed cho hàm rand() bằng thời gian hiện tại
    if(isPrime(n)==1)
    {
        return 0;
    }
    int b= rand()%(n-3) + 2; // min + (max-min+1) // b chay tu 2 -> n-2
    while(b<n)
    {
        if(GCD(b,n)==1)
        {
            if(nhanBinhPhuongCoLap(b,n-1,n)!=1)
            {
                return 0;
            }
        }
        b++;
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    long long int count =0, sum=0;
    for(long long int i=2; i<=t; i++)
    {
        if(isCarmichael(i)==1)
        {
            count++;
            sum+=i;
            printf("%d ",i);
            
        }
    }
    printf("\nC29: %lld ",count);
    printf("\nC30: %lld ",sum);
}