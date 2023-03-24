#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>

int isPrime(int n){
    if(n < 2){
        return 0;
    }
    int count = 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            count++;
        }
    }
    if(count == 0){
        return 1;
    }else{
        return 0;
    }
}

int nhanBinhPhuongCoLap( int a,int k, int n)
{
    int b=1;
    int A=a;
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

int main(){
    int p, q;
    srand(time(NULL));
    while(1){
        p = rand() % 1000;
        q = rand() % 1000;
        if(isPrime(p) && isPrime(q)){
            break;
        }
    }
    printf("p = %d\n", p);
    printf("q = %d\n", q);
    for(int a = 1; a < 100; a++){
        if(isPrime(nhanBinhPhuongCoLap(a,p,q))){
            printf("%d  ", a);
        }
    }
    return 0;
}
