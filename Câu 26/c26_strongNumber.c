#include<stdio.h>

int isPrime(int n)
{
    if(n<=1) return 0;
    for(int i=2;ii<=n;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

int main()
{
    int n,check=0;
    do{
        scanf("%d",&n);
    }while(n>=10000);

    for(int i = 1; i<n;i++)
    {
        for(int j = 1;j<i;j++)
        {
            if(isPrime(j)==1)
            {
                if(i%j==0 && i%(j*j)==0)
                {
                     printf("\n%d ",i);
                    //printf("\n%d chia het cho %d va %d ^ 2",i,j,j);
                    check =1;
                }
            }
        }
    }
    if(!check) printf("Khong co so S-num nho hon %d",n);

}
