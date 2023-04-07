#include <stdio.h>
#include <math.h>
int isPrime(long long int n){
    if (n <= 1)
        return 0;
    for(int i =2;i*i<=n;i++)
	{
		if(n%i==0) return 0;
	}
	return 1;
    
}
int main(){
    long long int n, d1=0, d2=0;
    scanf("%lld",&n);
    while(n<=0){
        printf("Nhap n thoa man de bai: ");
        scanf("%lld",&n);
    }
    for(long long int i=1;i<=n;i++)
        if(n%i==0){
            d1+=1;
            if(isPrime(i)==1)
                d2+=1;
        }
    printf("So uoc cua N la: %lld\nSo uoc nguyen to cua N la: %lld",d1,d2);        
    return 0;
}
