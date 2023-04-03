#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
    if(n<=1) return 0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

int prime_sum(int n, int m, int a[]) 
{
    if (m == 1) 
    {
        if (isPrime(n)) 
        {
            a[0] = n;
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    for (int i = 2; i < n; i++) 
    {
        if (isPrime(i)) 
        {
            if (prime_sum(n - i, m - 1, a + 1))  // nếu i là số nguyên tố lúc này n = i+ ...
            //Vì vậy cần tìm prime_sum(n-1,m-1,a+1) với a+1 là vị trí kế tiếp của i
            {
                a[0] = i;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n, m, i;
    scanf("%d%d",&n,&m);
    
    int a[100];
    if (prime_sum(n, m, a))
    {
       printf("n= ");
        for (i = 0; i < m; i++) 
        {
            printf("%d",a[i]);
            if (i != m - 1) {   // nếu i không phải là số cuối cùng thì thêm dấu +
                printf(" + ");
            }
        }
        
    }
    else {
        printf("khong the phan tich %d thanh tong cua %d so nguyen to",n,m);
    }
    return 0;
   
}