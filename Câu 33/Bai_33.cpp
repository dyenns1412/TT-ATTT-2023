#include <stdio.h>
#include <string>
int qq,rr,xx,yy,aa,bb,xx2,xx1,yy1,yy2;
int q[10],r[10],x[10],y[10],a[10],b[10],x2[10],x1[10],y1[10],y2[10];
void tinh_r_q()
{
   int i,cMax,BacChia,x,t;
   int c[10];
   int m=aa;
   for(i=aa;i>=0;i--)c[i]=0;
    cMax=aa-bb;
   while(aa>=bb)
    {
        BacChia=aa-bb;
        x=a[aa]/b[bb];
        c[BacChia]=x;
        for(i=bb;i>=0;i--)
        {
            t=BacChia+i;
            a[t]=(a[t]+b[i]*x)%2;
        }
        while(a[aa]==0)aa--;
    }
    qq=m;
    rr=m;
    while(a[rr]==0) --rr;
    for (i=rr; i>=0; i--)
        r[i]=a[i];
    while(c[qq]==0) --qq;
    for (i=qq; i>=0; i--)
        q[i]=c[i];

}
void tinh_x_y()
{
   int i,j,m;
   for (i=0; i<=qq+xx1; i++)x[i]=0;
   for (i=0; i<=qq; i++)
    for (j=0; j<=xx1; j++)
        {
            x[i+j]=x[i+j]+q[i]*x1[j];
        }
   if (qq+xx1<xx2) m=xx2;
   else
     m=qq+xx1;

   for(i=m; i>=0; i--)
   {
       if (i>qq+xx1) x[i]=0;
       if (i>xx2) x2[i]=0;
   }
   xx=m;
   for (i=m; i>=0; i--)
   {
       x[i]=x2[i]-x[i];
       if (x[i]<0) x[i]=-x[i];
       if (x[i]%2==0) x[i]=0;
   }
   while (x[xx]==0)--xx;
   for (i=0; i<=qq+yy1; i++)y[i]=0;

   for (i=0; i<=qq; i++)
    for (j=0; j<=yy1; j++)
        {
            y[i+j]=y[i+j]+q[i]*y1[j];

        }
   if (qq+yy1<yy2) m=yy2;
   else
     m=qq+yy1;

   for(i=m; i>=0; i--)
   {
       if (i>qq+yy1) y[i]=0;
       if (i>yy2) y2[i]=0;
   }
   yy=m;

   for (i=m; i>=0; i--)
   {
       y[i]=y2[i]-y[i];

       if (y[i]<0) y[i]=-y[i];
       if (y[i]%2==0) y[i]=0;
   }
   while (y[yy]==0)--yy;

}

int main()
{

    int i,t,cMax,BacChia,m;
    printf("nhap bac cua mang A: ");
    scanf("%d",&aa);
    m=aa;
    for(i=aa;i>=0;i--)scanf("%d",&a[i]);
    printf("nhap bac cua mang B: ");
    scanf("%d",&bb);
    for(i=bb;i>=0;i--)scanf("%d",&b[i]);
    xx2=1;
    x2[0]=1;
    xx1=0;
    yy2=0;
    yy1=1;
    y1[0]=1;
    while(bb>=0)
    {
        tinh_r_q();
        tinh_x_y();
        aa=bb;
        if (bb==0)
        {
            for(i=yy1;i>=0; i--) printf("%d ",y1[i]);
            bb=-1;
        }
        else
        {
             for (i=0; i<=aa; i++)a[i]=b[i];
             xx2=xx1;
             for(i=0;i<=xx2; i++) x2[i]=x1[i];
             yy2=yy1;
             for(i=0;i<=yy2; i++) y2[i]=y1[i];
             bb=rr;
             for(i=0; i<=bb; i++)b[i]=r[i];
             xx1=xx;
             for(i=0;i<=xx1; i++) x1[i]=x[i];
             yy1=yy;
             for(i=0;i<=yy1; i++) y1[i]=y[i];
        }

    }





}
