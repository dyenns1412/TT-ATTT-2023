#include <stdio.h>
#include <math.h>

void solve(int n)
{
    int prime[n+1];
    for(int i=0; i<=n; i++)
        prime[i] = 1;
    prime[0] = prime[1] = 0;
    for(int i=2; i<=sqrt(n); i++)
    {
        if(prime[i])
        {
            for(int j=ii; j<=n; j+=i)
                prime[j] = 0;
        }
    }

    for(int i=2; i<n; i++)
    {
        for(int j=2; j<=i; j++)
        {
            if(prime[j] && i%j==0 && i%(jj)==0)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    solve(n);

    return 0;
}
