#include<stdio.h>
#include<math.h>

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

int sum (int i, int j)
{
    if(isPrime(i)==0 || isPrime(j)==0) return 0;
    else return i*j;

}
int main()
{
    int l, r;
    scanf("%d %d", &l, &r);

    for (int i = l; i < r; i++)
    {
        for (int j = i+1; j <= r; j++)
        {
            printf("\n F(%d) * F(%d) = %d\n", i, j, sum(i,j));
            
        }
    }
    
    return 0;
}