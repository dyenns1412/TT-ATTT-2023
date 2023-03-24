#include<stdio.h>

int sumDivisor(int a)
{
    int sum = 0;
    for (int i = 1; i <= a/2; i++)
    {
        if (a % i == 0)
        {
            sum += i;

        }
    }
    return sum;
}

int main()
{
    int N;
    scanf("%d", &N);
    int check=0;
    for (int i=1; i<=N;i++)
    {
        int j = sumDivisor(i);
        if(sumDivisor(j)==i && j>i && j<N) // (j>i) để loại trường hợp i j đảo vị trí cho nhau
        { 
            printf("%d %d\n",i,j);
            check =1;
        }
    }
    if(check==0) printf("Khong ton tai cap so nho hon N < %d",N);

    return 0;
}