#include<stdio.h>

int check(int a)
{
    if (a == 1) return 0; 
    if (a == 2) return 1;
    for (int i = 2; i*i <= a; i++)
    {
        if (a % i == 0) return 0;
    }
    return 1;
}

int main()
{
    int N, k = 0, q = 0, p = 0, s = 0;
    scanf("%d", &N);
    for (int i = 1; i*i <= N; i++)
    {
        if (N % i == 0)
        {
            s++;
            p += i;
            if (check(i) == 1)
            {
                k++;
                q += i;
            }
            int j = N/i;
            if (i != j)
            {
                s++;
                p += j;
                if (check(j) == 1)
                {
                    k++;
                    q += j;
                }
            }
            
        }
        
    }
    printf("%d", N+p+s-q-k);
    return 0;
}