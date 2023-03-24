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

int main(){
    int n, check = 0;
	scanf("%d",&n);

	for (int i=1; i<=n;i++){
		if(demSoUoc(i)==3){
			printf("%d\n",i);
            check =1;
		}
	}
    if(check==0) printf("Khong ton tai so TPrime nho hon %d",n); 
}
