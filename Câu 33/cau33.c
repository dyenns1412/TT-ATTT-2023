#include <stdio.h>
#include <math.h>
#define MAX 100

int bac;

void nhap (int a[])
{
	int deg;
	printf("Nhap bac cua da thuc: ");
	scanf("%d", &deg);
	printf("Nhap cac he so\n");
	for(int i=deg; i>=0; i--)
	{
		printf("x^%d = ", i);
		scanf("%d", &a[i]);
	}	
}

void xuat (int a[])
{
	printf("\nNghich dao cua da thuc a(x)\n");
	for(int i=bac; i>=0; i--)
	{
		if(a[i] != 0)
		{	
			printf("x^%d", i);			
			if(i!=0)
			{
				if(a[i-2] != 0 || a[i-1] != 0)
				printf(" + ");	
			}
							
		}
	}
	printf("\n");	
}

void KhoiTao (int a[], int x)
{
	for(int i=0; i<=bac*2; i++)
		a[i] = x;
}

void CapNhat (int x[], int y[])
{
	for(int i=0; i<=bac; i++)
		x[i] = y[i];
}

void chia (int x[], int y[], int nguyen[], int du[])
{		
	KhoiTao(nguyen, 0);
	KhoiTao(du, 0);	
    for(int i=0; i<=bac*2; i++)
    	du[i] = x[i];
    int deg_x = bac;
	int deg_y = bac;		
	while(x[deg_x] == 0)
		deg_x--;
	while(y[deg_y] == 0)
		deg_y--;
    while(deg_x >= deg_y)
    {
    	int deg_ng = deg_x - deg_y;
    	nguyen[deg_ng] = 1;
    	for(int i=deg_y; i>=0; i--)
    	{
    		if(y[i] == 1)
    			du[i + deg_ng] = (du[i + deg_ng] + 1) % 2;
		}
		while(du[deg_x] == 0)
			deg_x--;
	}
}

void nhan (int x[], int y[], int kq[])
{	
	int deg_x = bac;
	int deg_y = bac;		
	while(x[deg_x] == 0)
		deg_x--;
	while(y[deg_y] == 0)
		deg_y--;
    KhoiTao(kq, 0);
    while(deg_y >= 0)
    {
    	if(y[deg_y] != 0)
    	{
    		for(int i=deg_x; i>=0; i--)
    		{
    			if(x[i] == 1)
    				kq[i + deg_y] = (kq[i + deg_y] + 1) % 2;
			}
		}
		deg_y--;
	}
}

int max (int a, int b)
{
	return a>b ? a:b;
}

void cong (int x[], int y[], int kq[])
{	
	int deg_x = bac;
	int deg_y = bac;		
	while(x[deg_x] == 0)
		deg_x--;
	while(y[deg_y] == 0)
		deg_y--;
	int deg_kq = max (deg_x, deg_y);		
	while(deg_kq >= 0)
	{
		kq[deg_kq] = (x[deg_kq] + y[deg_kq]) % 2;
		deg_kq--;
	}
}

int test (int a[])
{
	for(int i=bac; i>=0; i--)
	{
		if(a[i] == 1)
			return 1;
	}
	return 0;
}

int main()
{
	printf("Nhap bac cua truong: ");
	scanf("%d", &bac);
	
	int q[MAX], r[MAX];
	int a[MAX], b[MAX], x[MAX], y[MAX];
	KhoiTao(a, 0);
	KhoiTao(b, 0);
	KhoiTao(x, 0);
	KhoiTao(y, 0);
	printf("Nhap da thuc a(x)\n");	
	nhap(a);
	printf("Nhap da thuc g(x)\n");
	nhap(b);
	
	int x1[MAX], x2[MAX], y1[MAX], y2[MAX];
	KhoiTao(x1, 0);
	KhoiTao(x2, 0);
	KhoiTao(y1, 0);
	KhoiTao(y2, 0);
	x2[0] = 1;
	y1[0] = 1;
	
	while(test(b) != 0)
	{
		chia (a, b, q, r);

		nhan (q, x1, x);
		cong (x, x2, x);
		
		nhan (q, y1, y);
		cong (y, y2, y);
		
		CapNhat (x2, x1);
		CapNhat (x1, x);
		CapNhat (y2, y1);
		CapNhat (y1, y);
		
		CapNhat (a, b);
		CapNhat (b, r);
	}
	xuat (x2);

	return 0;
}

