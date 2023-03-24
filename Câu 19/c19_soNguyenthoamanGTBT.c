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
    int m,l;
    scanf("%d %d", &m, &l);
     while (m >= l || m < 0 || l <= 0)
    {
        printf("Nhap 0 <= m < l!\n");
        scanf("%d %d", &m, &l);
    }
    int  A, B, C;
    scanf(" %d %d %d",  &A, &B, &C);
    printf("A = %d; B = %d; C = %d\n", A, B, C);
    int check = 0;
    for (int i = m; i < l; i++)
    {
        if (isPrime(A*i*i + B*i + C) == 1)
        {
            printf("x=%d", i);
            check = 1;
            break;
        }
    }
    if(!check) printf("Khong co x thoa man");

    return 0;
}