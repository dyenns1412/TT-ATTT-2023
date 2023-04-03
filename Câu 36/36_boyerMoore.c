#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0
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

int isMatch(char *T, int x)
{
	for(int i=0; i<x; i++)
	{
		if(T[i] == T[x])
			return 0;
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
	int flag = 0;	
	
	while(i <= strlen(T))
	{
		if(T[i] != P[j])
		{
			i = i + m - min(j, 1 + lastOccurrence(P, T[i]));
			j = m - 1;
		}
		else
		{			
			if(j == 0)
			{			
				printf("\nVi tri xuat hien cua P trong T la %d", i);
				flag = 1;
				break;
			}
			i--;
			j--;
		}
	}
	if(flag == 0) 
		printf("\nNot found!");		
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


