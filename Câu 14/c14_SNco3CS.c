#include<stdio.h>
#include<math.h>

// output: 521

int demUoc(int a)
{
    int b = 0;
    for (int i = 1; i*i <= a; i++)
    {
       if (a % i == 0)
       {
            b++;
            int j = a/i;
            if (j != i) b++;
       }
       
    }
    return b;
}

int daoSo(int a)
{
    int b = 0;
    while (a > 0)
    {
        b = b*10 + a%10;
        a /= 10;
    }
    return b;
}

int soLapPhuong(int a)
{
    int d = 0;
    for (int i = 1; i*i*i <= a; i++)
    {
        if (i*i*i == a) d++;
    }
    return d;
}

int main()
{
    for (int i = 100; i <= 999; i++)
    {
        if (demUoc(i) == 2)
        {
            int j = daoSo(i);
            if (soLapPhuong(j) == 1) printf("%d ", i);
        }
        
    }
}