#include<stdio.h>
#include<math.h>

int isPrime(int n)
{
    if(n<2) return 0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

int main()
{
    int n, dem1=0, dem2=0;
    scanf("%d", &n);
    
    for(int i=1;i<=n;i++)
    {
        if(n%i==0){
            dem1+=1;
            if(isPrime(i)==1)
                dem2+=1;
        }
    }
    printf("So uoc cua N la: %d\nSo uoc nguyen to cua N la: %d",dem1,dem2);     

    return 0;
}
