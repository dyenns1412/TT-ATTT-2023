#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isPrime(int a)
{
    if (a == 1) return 0;
    if (a == 2) return 1;
    for (int i = 2; i*i <= a; i++)
    {
        if (a % i == 0) return 0;
    }
    return 1;
}

int main() {
    int N; // số phần tử của mảng
    scanf("%d", &N);
    int a[N]; // khai báo mảng a với N phần tử
    
    srand(time(NULL)); // thiết lập seed cho hàm rand() bằng thời gian hiện tại
    
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 100000; // giá trị ngẫu nhiên từ 0 đến 9999
    }
    
    // in ra các giá trị trong mảng
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }

    // in ra các giá trị là số nguyên tố
    printf("\nMang SNT la: ");
    for (int i = 0; i < N; i++)
    {
        if (isPrime(a[i]) == 1) printf("%d ", a[i]);
    }
    
    return 0;
}