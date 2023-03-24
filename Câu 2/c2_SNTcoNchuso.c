#include<stdio.h>
#include<math.h>

int demUoc(int n)
{
    int dem=2; //ước là 1 và n
    for(long long int i=2;i<=n/2;i++)
        if(n%i==0)
            dem+=1;
    return dem;
}

int main()
{
    int N;
    while(N<2 || N>10)
    {
        scanf("%d", &N);
    }
    
    for (int i = pow(10, N-1); i < pow(10, N); i++)
    {
        if (demUoc(i) == 2) printf("%.1lf\n ", (double)i);
    }
    
    return 0;
}