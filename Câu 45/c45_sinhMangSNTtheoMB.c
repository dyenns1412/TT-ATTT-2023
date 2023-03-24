#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int isPrime(int a)
{
    if (a<=1) return 0;
    for (int i = 2; i*i <=a; i++)
    {
        if( a % i == 0) return 0; 
    }
    return 1;
}

int nhanBinhPhuongCoLap(int a, int k, int n)
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


int Miller_Rabin(int n, int t)
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


void primeArray (int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		while(!Miller_Rabin(a[i], 10))
			a[i] = rand() % 99999; 			
	}
}


void output(int a[], int n)
{
    for(int i=0; i<n;i++)
    {
        printf("%d ",a[i]);
    }

}


void solve(int a[], int n)
{
    int MIN= a[0];
    for (int i=0; i<n;i++)
    {
        for(int j=i+1; j<n;j++)
        {
            MIN = MIN< (abs(a[i]-a[j])) ? MIN : abs(a[i]-a[j]);
        }
    }
    printf("\nMIN = %d ",MIN);
}


int main()
{
    int n, a[100000];
    printf("Nhap so phan tu cua n:");
    scanf("%d", &n);
    srand(time(NULL));
    primeArray(a,n);
    output(a,n);

    solve(a,n);
    return 0;
}