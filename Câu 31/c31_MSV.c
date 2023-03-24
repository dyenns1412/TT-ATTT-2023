#include<stdio.h>
#include<math.h>
// tinh a^k mod n với với a = SBD, n = 123456, số nguyên tố k gần nhất với phần số của MSV 
int isPrime(int n)
{
    if(n<=1) return 0;
    for(int i=2; i*i<=n;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}


int find_Prime(int n)// tìm số nguyên tố gần n nhất
{
    int min, max;
    int a = 0, b = 0;
    if(isPrime(n)) return n;
    else 
    {
        min = max = n;
        while(1) // kiểm tra SNT lớn hơn n
        {
            min++;
            if(isPrime(min) == 1)
            {
                a = min;
                break;
            }
        }
        while(1) // kiểm tra số nguyên tố nhỏ hơn
        {
            max--;
            if(isPrime(max) == 1)
            {
                b = max;
                break;
            }
        }
        if(abs(a - n) <= abs(b - n)) return a;
        else
            return b;
    }
}

long long int nhanBinhPhuongCoLap(long long int a, long long int k, long long int n)
{
    long long int b=1;
    long long int A=a;
    if( k == 0)
        return b;
    else
    {
        if(k % 2 == 1)
            b = a;
        k /= 2;
        while(k != 0)
        {
            A = A*A % n;
            if(k % 2 == 1)
            {
                b = A*b %n;
            }
            k /= 2;
        }

    }

    return b;

}

int main()
{
    long long int a = 180251, n=123456;
    
    printf("k = %lld\n", find_Prime(a));
    printf("kq = %lld ", nhanBinhPhuongCoLap(a,find_Prime(a),n));
   
}