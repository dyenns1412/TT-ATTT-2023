#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define true 1
#define false 0
#define MAX 1000

void failureFunction(char *P, int *F)
{
	int i = 0;
	int j = 2;
	F[0] = -1;
	F[1] = 0;
	
	while(j < strlen(P))
	{
		if(P[i] == P[j-1])  // tiền tố = hậu tố
		{
			F[j] = i + 1;// F[j]= độ dài của tiền tố +1 
			i++;  // tăng i và j lên 1đv để tiếp tục so sánh
			j++;
		}
		else
			F[j++] = 0;
	}
	
	printf("\nFailure function\n");
	printf("%5s", "P");	
	for (int i=0; i<strlen(P); i++)
		printf("%5s", P[i]);
	printf("\n");
	printf("%5s", "j");	
	for (int i=0; i<strlen(P); i++)
		printf("%5d", i);
	printf("\n");
	
	printf("%5s", "F(j)");	
	for(int k=0; k<j; k++)
		printf("%5d", F[k]);
	printf("\n");
}

int KMPSearch (char *T, char *P, int *F)
{
	int i = 0, j = 0;
	
	while(i < strlen(T))
	{
		int inew=i+j;
		if(T[inew] == P[j]) // nếu khớp nhau thì tăng j
		{
			inew++;
			j++;
			if(j == strlen(P)) // j tăng đến hết P. kiểm tra toàn bộ chuỗi đã khớp chưa
				return i;
		}
		else
		{
			if(F[j] == -1)  
			{
				i++;
				j = 0;
			}
			else // nếu F[j] khác 0.cập nhật gtri mới của i và j
			{
				i = i + j - F[j];
				j = F[j];
			}
		}			
	}
	return -1;
}


int main()
{
	char T[MAX], P[MAX];
	int F[MAX];
	printf("Nhap chuoi T: ");
	gets(T);
	printf("Nhap chuoi P: ");
	gets(P);
		
	failureFunction(P, F);	
	if(KMPSearch(T, P, F) != -1)
		printf("\nVi tri xuat hien cua P trong T la %d", KMPSearch(T, P, F));
	else
		printf("\nNot found!");

	return 0;
}
/*
	Truong hop cai tien hon Boyer Moore
	T = "aaaaaaaaaa"
	P = "baaaa"
*/

