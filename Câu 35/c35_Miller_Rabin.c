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

int miller_rabin(int n, int t)
{
    if(n<=1 || n==4) return 0;
    if(n<=3) return 1;

    int d=n-1;
    int s=0;
	while (d % 2 == 0) // do d phai la so le
	{
		d /= 2;
        s += 1;
	}
	int m=d;
	srand(time(NULL));
    for (int i=1; i<=t;i++)
	{
		int a = 2 + rand() % ( n-2 + 1 -2);
		int y = nhanBinhPhuongCoLap(a,m,n);
		if(y!=1 && y!= (n-1))
		{
			int j =1;
			while(j<=s && y!=(n-1))
			{
				y=nhanBinhPhuongCoLap(y,2,n);
				if(y==1) return 0;
				j+=1;
			}
			if(y!=(n-1)) return 0;
		}
	}
	return 1;

}

int main()
{
    int n, t;
    scanf("%d%d", &n, &t);
    
    for(int i=1;i<=n;i++)
    {
        if(miller_rabin(i,t)==1) printf("%d\t", i);
    }
    
    return 0;

}