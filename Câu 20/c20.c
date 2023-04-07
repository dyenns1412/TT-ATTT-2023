#include <stdio.h>
#include <math.h>

int gcd(int a, int b)
{
    int temp;
    while(b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main()
{
    int i,j;
    int m,n,d;
    printf("Nhap M=");
    scanf("%d",&m);
    printf("Nhap N=");
    scanf("%d",&n);
    printf("Nhap D=");
    scanf("%d",&d);
    for(i=m ;i<n;i++)
    {
        for(j=i;j<=n;j++)
        {

            if(gcd(i,j)==d) printf("(%d;%d)\t",i,j);
        }
    }
}
