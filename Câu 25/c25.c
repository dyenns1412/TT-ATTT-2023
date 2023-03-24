#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int m;
    while (n<1 || n>10000 || m<2 || m>100)
    {
        printf("Nhap n : ");
        scanf("%d",&n);
        printf("Nhap m : ");
        scanf("%d",&m);
    }
    
    int arrayPrime[100];
    int k=0;
    int sum=0;

    for(int i=2;i<=n; i++)
    {
        int count=0;
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                count++;
                break;
            }
        }
        if(count ==0)
        {
            k++;
            arrayPrime[k] = i;
        }
    }
    for(int i=1; i<=m;i++)
    {
        sum +=arrayPrime[i];
    }
    if(sum==n)
    {
        for(int i=1;i<=m;i++)
        {
        printf("%d\t",arrayPrime[i]);
        }
    }
    return 0;
}