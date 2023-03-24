#include<stdio.h>
#include<math.h>

int Extended_Euclide (int a, int b)  
{
    int t = b;
    int x1=0, x2=1, y1=1, y2=0, q, r, x, y, d;
    while(b>0)
    {
        q = a / b;
        r = a - q*b;
        x = x2 - q*x1;
        y = y2 - q*y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    d = a;
    x = x2;
    y = y2;

    if (x<0) return x+t;  // -5(mod13)= 8(mod13)
    return x;            // trả về số nghịch đảo của a
}

int main()
{
    int p, n;
    scanf("%d %d",&p,&n);
   
    int A[10001], B[10001];
    for (int i=1; i<=n; i++)
    {
        scanf("%d",&A[i]);
    }
     
    for (int i=1; i<=n; i++)
    {
        int a = A[i];
        int b = Extended_Euclide (a,p);
        B[i]=b;
    }

    for (int i=1; i<=n; i++)
    {
        printf("%d  %d\n",A[i],B[i]);
    }
        
    return 0;
}



