#include<stdio.h>
#include<string.h>
#include<math.h>

int isPrime(int n)
{
    if(n <= 1) return 0;
    for(int i =2; i*i <= n;i++)
    {
        if(n % i == 0) return 0;
    }
    return 1;
}

long long int nhanBinhPhuongCoLap(long long int a, long long int k,long long int n)
{
    long long int b =1 , A =a;
    if(k % 2 == 1) b=a;
    k /= 2;
    while(k != 0)
    {
        A = (A * A) % n;
        if(k % 2 == 1)
        {
            b = (b * A) %n;
        }
        k /= 2;
    }
    return b;
}

int main()
{
    long long int MSV,SBD, n= 123456;
    printf("Nhap MSV va SBD:\n");
    scanf("%lld%lld", &MSV,&SBD);
    long long int x1, x2, k;
    for(int i = MSV ; i>=2 ;i--)  // SNT lon nhat nho hon hoac bang k
    {
        if(isPrime(i)==1)
        {
            x1 = i;
            break;
        }
    }
    
    for(int i = MSV; i< 2*MSV;i++)  // SNT nho nhat lon hon hoac bang k
    {
        if(isPrime(i)==1)
        {
            x2 = i;
            break;
        }
    }
    
    k = (MSV - x1) <= (x2 - MSV) ? x1 : x2;
    // if((SBD - x1) == (x2 - SBD)) k = x1 ;
    
    printf("SNT gan nhat voi %d la %d", MSV, k);
    
    int kq = nhanBinhPhuongCoLap(SBD,k,n);
    printf("\n %d ^ %d (mod %d) = %d", SBD, k,n,kq);

    return 0;
}
