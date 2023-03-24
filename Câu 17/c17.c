#include<stdio.h>

int isPrime(int a)
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
    int n;
    scanf("%d", &n);
    int  A, B, C;
    scanf(" %d %d %d",  &A, &B, &C);
    printf("A = %d; B = %d; C = %d\n", A, B, C);
    int min=0,check=0;
   
    for (int i = 1; i < n; i++)
    {
        if (isPrime(A*i*i + B*i + C) == 1)
        {
            printf("x = %d ", i);
            check = 1;
            break;
        }
    }
    if(!check) printf("Khong co x thoa man");

    return 0;
}