#include<stdio.h>
#include<math.h>

int gcd(int a, int b) 
{
    int tmp;
    while(b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main ()
{  //(0<M,N, D < 1000).
    int m, n, d;
    while (m>=n || m <= 0 || n<=0 || m >= 1000 || n>=1000){
        printf("Nhap 0 < M < N < 1000\n");
        scanf("%d %d", &m, &n);
    }

    while (d<=0 || d>=1000)
    {
        printf("Nhap 0 < D< 1000\n");
        scanf("%d", &d);
    }

    for( int i=m; i<n;i++)
    {
        for( int j=i+1; j<n+1; j++)
        {
            int UCLN = gcd(i,j);
            if(UCLN==d)
            { 
                printf("\n%d va %d\n%d va %d\n",i,j,j,i);
            }
        }
    }
     return 0;
}