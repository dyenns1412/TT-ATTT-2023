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
    int a, p;
    printf("Nhap a va p: ");
    scanf("%d %d",&a,&p);

    int kq = Extended_Euclide(a,p);
    printf("Nghich dao cua %d trong truong F%d la %d", a, p, kq); // a*kq= 1 (mod p)
        
    return 0;
}
