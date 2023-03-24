#include<stdio.h>
#include<math.h>

int main()
{
    int p = 2147483647, w = 8;
    int m= ceil(log2(p));
    int t = ceil(m/w);
    int a, b, A[t], B[t];
    scanf("%d %d", &a, &b);
    // bieu dien a nhu 1 mang A: a= (2^(t-1)w) * A[t-1]+...+ (2^w) *A[1]+A[0]
    for (int i = t-1; i >= 0; i--)
    {
        A[i] = a/pow(2, i*w);
        a = a - A[i]* pow(2, i*w);
        B[i] = b/pow(2, i*w);
        b = b - B[i]*pow(2, i*w);
    }

    printf("a = ( ");
    for (int i = t-1; i >= 0; i--) printf("%d ", A[i]);
    printf(")\n");

    printf("b = ( ");
    for (int i = t-1; i >= 0; i--) printf("%d ", B[i]);
    printf(")\n");
    
    // thuc hien thuat toan cong
    int C[t], epsilon = 0;

    C[0] = (A[0] + B[0]) % (int)pow(2, w);
    if (A[0] + B[0] > pow(2, w)) epsilon = 1;

    for (int i = 1; i <= t-1; i++)
    {
        C[i] = A[i] + B[i] + epsilon;
        if (C[i] < 0 || C[i] > pow(2,w)) 
        {
            C[i] =  C[i] % (int)pow(2, w);
            epsilon = 1;
        }else {
            epsilon = 0;
        }
    }

    printf("(%d, (", epsilon);
    for (int i = t-1; i >= 0; i--) printf("%d ", C[i]);
    printf(") )\n");
    
    return 0;
}