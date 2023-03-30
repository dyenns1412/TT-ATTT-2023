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
	
	printf("\nFailure function\n");
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
		if(T[i+j] == P[j])
		{
			j++;
			if(j == strlen(P))
				return i;
		}
		else
		{
			if(F[j] == -1)
			{
				i++;
				j = 0;
			}
			else
			{
				i = i + j - F[i];
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

