#include<stdio.h>
// 2 SNT liên tiếp sao cho tổng và hiệu của chúng là 1 SNT
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
    int N, A[1000], k = 0;
    scanf("%d", &N);
    for (int i = 2; i <= N; i++)
    {
        if (check(i) == 1)
        {
            A[k] = i;
            k++;
        }
        
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = i+1; j < k; j++)
        {
            if (check(A[i] + A[j]) == 1 && check(A[j] - A[i]) == 1) printf("%d %d\n", A[i], A[j]);
        }
        
    }
    
    return 0;
}