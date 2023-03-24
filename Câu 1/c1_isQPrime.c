#include<stdio.h>
#include<math.h>
int demSoUoc(int n)
{
    int dem=2; //ước là 1 và n
    for(int i=2;i<=n/2;i++)
        if(n%i==0)
            dem++;
    return dem;
}

int main()
{
	int n;
	scanf("%d",&n);
	int dem1 = 0;
	for (int i=1; i<=n;i++)
	{
		if(demSoUoc(i)== 4)
		{
			printf("%d\n", i);
			dem1++;
		}
	}
	if(dem1 ==0 ) printf("No");

}