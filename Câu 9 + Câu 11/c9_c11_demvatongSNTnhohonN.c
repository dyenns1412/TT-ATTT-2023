#include <stdio.h>
#include <math.h>


int laSnt(int x)
{
	if(x<2)
		return 0;
	for(int i=2; i<=sqrt(x); i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}

void demSNT (int x)
{
    int dem=0;
    for(int i=0;i<=x;i++)
    {
        if(laSnt(i)==1)
            dem++;
           
    }
    printf("%d\n", dem);
}
void tongSNT (int x)
{
    int tong=0;
    for(int i=0;i<=x;i++)
    {
        if(laSnt(i)==1)
            tong+=i;
           
    }
    printf("%d\n", tong);
}

int main()
{
	int n;
	scanf("%d", &n);
	demSNT(n);
	tongSNT(n);
	return 0;
}