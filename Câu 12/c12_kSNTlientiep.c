#include<stdio.h>

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

int main()
{
    int N, k;
    int a[100];
    scanf("%d%d", &N, &k);
    
    int sum = 0;
    int count = 0;
    for (int i = 2; i <= N; i++) 
	{
        if (isPrime(i))
		{
            a[count] = i;
            count++;          
        }
    }
    for(int i=0; i<count-k; i++)
    {
		for (int j=0; j<k; j++)
   		{
   			sum += a[i+j];
			 				
		}
		  if(sum<=N && isPrime(sum))
			{
				
				for (int j=0; j<k; j++)
		   		{
		   			printf("%d ", a[j+i]);
				}
                printf("\n");
			}			
	}
         
    return 0;
}