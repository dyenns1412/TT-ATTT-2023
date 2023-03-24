#include<stdio.h>
#include<math.h>


void strongNumber (int n)
{
    
    int p[n+1];
    for (int i=0;i<=n;i++)
    {
        p[i]=1;
        p[0]=p[1]=0;
    }
    for (int i=2; i<=sqrt(n);i++)
    {
        if(p[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                p[j]=0;
            }
        }
 
    }
    for (int i=2; i<n;i++)
    {
        for(int j=2; j<=i;j++)
        {
            if(p[j]==1 && i%j==0 && i%(j*j)==0)
            {
                printf("%d chia het cho %d va %d^2\n",i,j,j);
                break;
            }
        }
    }
}

int main()
{
    int n, check=0;
    scanf("%d",&n);
    strongNumber(n);
    
    return 0;
}