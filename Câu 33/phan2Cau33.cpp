#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;


//===================================================================

//xác định bậc của đa thức 
int deg(vector<int> A)
{
    for(int i=A.size()-1;i>=0;i--)
        if(A[i]!=0) 
            return i;
}

//===================================================================

//Hàm cộng
vector<int> hamCong(vector<int> m, vector<int>n)
{
    vector<int> result=max(m,n);
    vector<int> Min=min(m,n);
    for(int i=0;i<Min.size();i++)
        result[i]^=Min[i];
    result.resize(deg(result)+1);
    return result;
}

//===================================================================

//Hàm nhân
vector<int> hamNhan(vector<int> A, vector<int> B) 
{
    int bacA = deg(A);
    int bacB = deg(B);

    vector<int> result(bacA+bacB+1,0);
    for (int i = A.size()-1; i >= 0; i--)
    {
        if (A[i]==0) continue;
        for (int j = B.size()-1; j >= 0; j--) 
            {
                if(B[j]==0) continue;
                result[i+j]^=1;
            }
    }
    return result;
}


//===================================================================

//Hàm module
vector<vector<int>> module(vector<int> A, vector<int> B) {
    vector<vector<int>> Q_R;
    //xác định bậc của A và B
    int n = deg(A), m = deg(B);

    // Trường hợp đa thức chia lớn hơn đa thức bị chia
    if (n < m)
    {   
        Q_R.push_back(vector<int> {0});
        Q_R.push_back(A);   
        return Q_R;
    }

    vector<int> Q(n-m+1,0);
    while (n>=m)
    {
        Q[n-m]++;
        vector<int> K(n-m+1,0);
        K[n-m]++;   
        A=hamCong(A,hamNhan(K,B));
        n=deg(A);
        if(n==0&&A[0]==0)
            break;
    }
    Q_R.push_back(Q);
    Q_R.push_back(A);
    return Q_R;
}
//===================================================================

vector<int> khoi_tao_gia_tri()
{
    cout<<"Bac cua da thuc: ";
    int deg;
    cin >> deg;
    cout<<"Moi nhap he so cua da thuc: ";
    vector<int> a(deg+1,0);
    for(int i=deg;i>=0;i--)
        cin >> a[i];
    return a;
}

int main()
{
    //q     r	x	y	a	b	x2	x1	y2	y2
    //Tạo các giá trị của bảng tính nghịch đảo
    vector<int> q, r, x, y;
    vector<int> a, b, x2, x1, y2, y1;


    //Khoi tao cac gia tri ban dau
//============================================================

    //a= g(x) = x^3 + x + 1
    cout<<"NHAP DA THUC A"<<endl;
    a=khoi_tao_gia_tri();
    x2.push_back(1);
    y1.push_back(1);
    x1.push_back(0);
    y2.push_back(0);

    //b = a(x)
    // cout << "Vi la truong huu han GF(2^3) nen bac 2 la bac max"<<endl;
    // cout << "Nhap f(x)= Ax^2 + Bx + C"<<endl;
    // cout << "A, B, C lan luot la: ";
    cout<<"NHAP DA THUC B"<<endl;
    b=khoi_tao_gia_tri();

//============================================================

    //Tính toán các giá trị
    while(1)
    {
        //tính q và r
        vector<vector<int>> Q_R = module(a,b);
        q=Q_R[0]; //với Q_R là ma trận chứa dư và phần kết quả
        // Q_R[0] được gán với giá trị q
        // Q_R[1] được gán với giá trị r
        r=Q_R[1];
        //x=x2-q.x1
        x=hamCong(x2,hamNhan(q,x1));
        //y=y2-q.y1
        y=hamCong(y2,hamNhan(q,y1));
        //Theo công thức
        a=b;
        b=r;
        x2=x1;
        y2=y1;
        x1=x;
        y1=y;
        //Kiểm tra xem b = 0 chưa
        //Nếu bằng thì break, ngược lại thì tiếp tục
        if(deg(b)==0 && b[0]==0)
            {break;}
    }
    cout << "Da thuc nghich dao can tim la: ";
    for(int i=y2.size()-1;i>=0;i--)
    {
        if(i!=y2.size()-1&&y2[i]!=0) 
            cout<<" + ";
        if(y2[i]!=0)    
            cout<<"x^"<<i;
    }
    getchar();
    getchar();
    return 0;
}