#include<stdio.h>
#include<math.h>

int isPrime(int n)
{
    if (n<=1) return 0;
    for (int i=2; i*i<=n;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

int gcd(int a, int b) {  // khử đệ quy
    int tmp;
    while(b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main ()
{  
    int a, b;
    scanf("%d %d", &a, &b);
   
    for( int i=a; i<=b;i++)
    {
        for( int j=i+1; j<=b; j++)
        {
            if(isPrime (gcd(i,j)))
            { 
                printf("(%d, %d) = %d\n", i, j,gcd(i,j));
            }
        }
    }
     return 0;
}