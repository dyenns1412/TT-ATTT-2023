#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

long long nhanBinhPhuongCoLap(long long a, long long k, long long n)
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

int fermat(int n, int t) // t là số lần kiểm tra
{
    if(n<=1 || n==4) return 0;
    if(n<=3) return 1;

	srand(time(NULL));
    for (int i=1; i<=t;i++)
	{
		int a = 2 + rand() % ( n-2 + 1 -2);
		int r = nhanBinhPhuongCoLap(a,n-1,n);
        if(r!=1) return 0;
	}
	return 1;

}

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    
    for(int i=1;i<=n;i++)
    {
        if(fermat(i,t)==1) printf("%d\t", i);
    }
    
    return 0;

}