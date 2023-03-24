#include<stdio.h>
#include<string.h>

void LastOccurrence(char P[], int size, int L[256])
{
    int i;
    for (i = 0; i < 256; i++)
    {
        L[i] = -1;               // gán tất cả giá trị=-1 : không tồn tại chỉ số i
    }
    for (i = 0; i < size; i++)
    {
        L[(int)P[i]] = i;        // vị trí cuối cùng của kí tự có trong chuỗi
    }

}

int main(){
    char T[1000],P[1000];

    printf("Nhap chuoi T: ");
    gets(T);

    printf("Nhap chuoi P: ");
    gets(P);
    int m= strlen(P);
    int i= m-1, j=m-1, min, check=0;
    int L[256];
    LastOccurrence(P, m, L);
    while( i < strlen(T))
    {
        if(T[i]==P[j])
        {
            if(j==0)
            {
                printf("P co xuat hien trong T, co vi tri bat dau la %d",i);
                check=1;
                break;
            }
            i--; j--;    // inew=i-1; jnew=j-1
        }
        else{
            // inew=i+m-min(j,1+L(T[i])), jnew=m-1
            min = j < (1 + L[T[i]]) ? j : (1 + L[T[i]]) ;
            i = i+m-min;      
            j = m-1;
        }
    }
    if(check==0) printf("P khong xuat hien trong T!");
}