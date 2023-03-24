#include <stdio.h>
#include <math.h>

int Bac=100;
int MAX(int a,int b)
{
    if(a<b)return b;
    return a;
}

void xuat(int a[])
{
    for(int i=Bac ;i>=0 ;i--)
        printf("%d ",a[i]);
}

void capnhat(int a[],int b[])
{
    for(int i=0;i<=Bac;i++)
        a[i]=b[i]%2;
}

int test(int a[])
{
    for(int x=Bac; x>=0 ;x--)
    {
        if(a[x]==1)  return 1;
    }
    return 0;
}

void KhoiTao(int a[],int x)
{
    for(int i=0;i<=Bac*2;i++)a[i]=x;
}

void Chia(int x[],int y[],int nguyen[],int du[])
{
    int xMax = Bac;
    int yMax = Bac;

    KhoiTao(nguyen,0);
    KhoiTao(du,0);

    for(int i=0 ;i<=Bac*2 ;i++) 
        du[i]=x[i];

    while(du[xMax]==0 && xMax>=0)
        xMax--;
    while(y[yMax]==0 && yMax>=0)
        yMax--;
    while(xMax>=yMax && yMax>=0)
    {
        int vt=xMax-yMax;
        nguyen[vt]=1;
        for(int i=yMax;i>=0;i--)
        {
            if(y[i]==1)   
                du[i+vt]=(du[i+vt]+1)%2;
        }
        while(du[xMax]==0&&xMax>=yMax)
            xMax--;
    }

}
void Nhan(int x[],int y[],int kq[])
{
    int xMax=Bac;
    int yMax=Bac;
    int i;
    KhoiTao(kq,0);
    while(x[xMax]==0 && xMax>=0)
        xMax--;
    while(y[yMax]==0 && yMax>=0)
        yMax--;
    while(yMax>=0)
    {
        if(y[yMax]!=0)
            for(i=xMax;i>=0;i--)
            {
                if(x[i]==1)
                    kq[i+yMax]=(kq[i+yMax]+1)%2;
            }
        yMax--;
    }
}
void Cong(int x[],int y[],int kq[])
{
    int xMax=Bac;
    int yMax=Bac;

    while(x[xMax]==0&&xMax>=0)
        xMax--;
    while(y[yMax]==0&&yMax>=0)
        yMax--;
    int kqMax=MAX(xMax,yMax);
    while(kqMax>=0)
    {
        kq[kqMax]=(x[kqMax]+y[kqMax])%2;
        kqMax--;
    }
}

void nhap(int *a)
{
    int i,n;
    printf("nhap bac cua da thuc:");
    scanf("%d",&n);
    for(i=n;i>=0;i--)
    {
        printf("nhap he so x^%d:",i);
        scanf("%d",&a[i]);
    }
}
int main()
{
    int m;
    //nhập Bậc trường
    printf("nhap bac cua truong:");
    scanf("%d",&Bac);

    //Khởi tạo mảng
    int a[100],b[100],x[100],y[100];
    KhoiTao(a,0);
    KhoiTao(b,0);
    KhoiTao(x,0);
    KhoiTao(y,0);
    printf("Nhap da thuc A\n");
    nhap(b);
    printf("Nhap da thuc G\n");
    nhap(a);

    int x1[100], x2[100];
    int y1[100], y2[100];
    KhoiTao(x1,0);
    KhoiTao(x2,0);
    KhoiTao(y1,0);
    KhoiTao(y2,0);

    x2[0]=1;y1[0]=1;
    int q[100], r[100];

    while ( test(b)!=0)
    {
        // Tính phần nguyên và phần dư
        Chia(a,b,q,r);
        // Cập nhật x và y
        Nhan(q,x1,x);
        Cong(x,x2,x);

        Nhan(q,y1,y);
        Cong(y,y2,y);

        // Cập nhật x2, x1, y2, và y1
        capnhat(x2,x1);
        capnhat(x1,x);
        capnhat(y2,y1);
        capnhat(y1,y);

        // Cập nhật a và b
        capnhat(a,b);
        capnhat(b,r);

    }
    xuat(y2);
    return 0;
}
