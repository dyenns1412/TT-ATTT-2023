#include <stdio.h>
#include <math.h>

int isPrime(int n)
{
    if( n<= 1) return 0;
    for (int i = 2; i*i <= n; i++)
    {
        if(n % i == 0) return 0;
    }
    return 1;
}

int main(){
    int a, b, count=0;
    scanf("%d %d", &a, &b);

    while (a >= b || a < 0 || b <= 0){
        scanf("%d %d", &a, &b);
    }

    int n1=sqrt(a + b);
    int S1[n1+1], S2[n1+1];

    for(int i = 1; i<=n1+1;i++){
        S1[i] = i*i;
        S2[i] = i*i;
    }   

    for(int i=1; i<n1+1;i++)
        for(int j=i+1;j<n1+1;j++)
        {
                int sum = S1[i]+S2[j];
                if(sum>=a && sum<=b)
                {
                    if(isPrime(sum))
                    {
                        printf("%d^%d + %d^%d = %d\n", i,2, j,2, sum);
                        count ++;
                    }
                }
    
        }
    printf("%d", count);
    return 0;
}