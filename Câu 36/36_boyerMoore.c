#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int min(int a, int b)
{
	return a<b ? a:b;
}

int lastOccurrence(char *P, char x)
{
	for(int i=strlen(P)-1; i>=0; i--)
	{
		if(P[i] == x)
			return i;
	}
	return -1;
}
// kiểm tra kí tự đã xuất hiện trước đó hay chưa.(kiểm tra phần tử trùng lặp
int isMatch(char *T, int x)
{
	for(int i=0; i<x; i++)
	{
		if(T[i] == T[x])
			return 0;// tránh trường hợp in ra 2 kí tự giống nhau.Các kí tự chỉ được in ra 1 lần duy nhất
	}
	return 1;
}

void table_L (char *T, char *P)
{	
	printf("\nLast occurrence\n");
	printf("%5s", "x");	
	for (int i=0; i<strlen(T); i++)
	{
		if(isMatch(T, i))
			printf("%5c", T[i]);
	}
	printf("\n");
	printf("%5s", "L(x)");	
	for(int i=0; i<strlen(T); i++)
	{
		if(isMatch(T, i))
			printf("%5d", lastOccurrence(P, T[i]));
	}
	printf("\n");
}

void BoyerMooreSearch(char *T, char *P)
{
	int m = strlen(P);	
	int i = m - 1;
	int j = m - 1;	
	int check = 0;	
	
	while(i <= strlen(T))
	{
		if(T[i] != P[j])  //inew=i+m-min(j,1+L(T[i])), jnew=m-1
		{
			i = i + m - min(j, 1 + lastOccurrence(P, T[i]));
			j = m - 1;
		}
		else
		{			
			if(j == 0)
			{			
				printf("\nVi tri xuat hien cua P trong T la %d", i);
				check = 1;
				break;
			}
			i--;  // Nếu khớp nhau thì i = i-1,j=j-1
			j--;
		}
	}
	if(check == 0) 
		printf("\nKhong tim thay!");		
}

int main()
{
	char T[MAX], P[MAX];
	printf("Nhap chuoi T: ");
	gets(T);
	printf("Nhap chuoi P: ");
	gets(P);
		
	table_L(T, P);
	BoyerMooreSearch(T, P);

	return 0;
}
/*
	Truong hop cai tien hon vet can
	T = "aaaaaaaaaab"
	P = "aab"
*/


