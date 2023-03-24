#include <stdio.h>
#include<stdlib.h>
#include <string.h>


void  failure_Function(char* P, int* F)
{
    int j = 2;// biến chạy số thứ tự trong bảng F
    int i = 0;// Biến chạy vị trí trong chuỗi P
    // mặc định vị trí 0 và 1 trong bảng là -1 và 0
    F[0] = -1;
    F[1] = 0;

    //kiểm tra tiền tố và hậu tố trùng nhau
    while(j < strlen(P))
    {
        if(P[j - 1] == P[i])
        {
            F[j] = i + 1;
            i++;
            j++;
        }
        else if(i > 0)
        {
            i = F[i];
        }
        else
        {
            F[j] = 0;
            j++;
        }
    }

    //Biểu diễn thông tin bảng
    printf("Bang Failure Function: \n ");

    for(int x = 1; x< 4*j; x++)
    {
        printf("-");
    }
    printf("\n");

    for(int x = 0; x< j; x++)
    {
        printf("|%3d", F[x]);
    }
    printf("|\n ");

     for(int x = 1; x< 4*j; x++)
    {
        printf("-");
    }
    printf("\n");

}

int kmp(char* T, char* P, int* F)
{

    int i = 0, j= 0;

    while(i+j < strlen(T))
    {
        if(P[j] == T[j+i])
        {
            j++;
            if(j == strlen(P))
            {
                return i;
            }
        }

        else
        {
            if(F[j] > -1)
            {
                j = F[j];
                i += j - F[j];
            }
            else
            {
                j = 0;
                i++;
            }
        }
    }
    return -1;


}


int main()
{
    char T[256];
    char P[256];
    int F[256];

    printf("Nhap chuoi T: ");
    gets(T);

    printf("Nhap chuoi P: ");
    gets(P);
    failure_Function(P,F);

    if(kmp(T,P,F) != -1)
        printf("Vi tri xuat hien P trong T la: %d", kmp(T,P,F));
    else printf("Khong tim thay!!!");

}
