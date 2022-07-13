#include <bits/stdc++.h>
using namespace std;
struct SinhVien
{
    string hoten;
    string lop;
    float dtb;
    SinhVien *next;
};
typedef struct List
{
    SinhVien *head;
    SinhVien *tail;
};
void initialize(List &Q)
{
    Q.head=NULL;
    Q.tail=NULL;
}
SinhVien *taoNote(SinhVien &sv)
{
    SinhVien *p=new SinhVien;
    if(p==NULL)
    {
        cout<<"Khong tao duoc note";
        exit(1);
    }
    p->hoten=sv.hoten;
    p->lop=sv.lop;
    p->dtb=sv.dtb;
    p->next=NULL;
    return p;
}
void insertNodeLast(List &Q,SinhVien *p)
{
    if(!Q.head)
        Q.head=Q.tail=p;
    else
    {
        Q.tail->next=p;
        Q.tail=p;
    }
}
void insertNodeFirst(List &Q,SinhVien *p)
{
    if(!Q.head)
        Q.head=Q.tail=p;
    else
    {
        p->next=Q.head;
        Q.head=p;
    }
}
void nhapDSSV(List &Q)
{
    int n;
    cout<<"Nhap so luong sinh vien: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        SinhVien sv;
        cout<<"Nhap ho va ten: ";
        fflush(stdin);
        getline(cin,sv.hoten);
        fflush(stdin);
        cout<<"Nhap lop hoc: ";
        getline(cin,sv.lop);
        fflush(stdin);
        cout<<"Nhap diem trung binh: ";
        cin>>sv.dtb;
        fflush(stdin);
        SinhVien *p=taoNote(sv);
        insertNodeFirst(Q,p);
    }
}
void xuatSV(SinhVien *p)
{
    cout<<p->hoten<<setw(15)<<p->lop<<setw(10)<<p->dtb<<endl;
}
void xuatDSSV(List Q)
{
    SinhVien *p = Q.head;
    cout<<setw(10)<<"Ho va ten"<<setw(20)<<"Lop hoc"<<setw(20)<<"Diem trung binh"<<endl;
    while(p!=NULL){
        xuatSV(p);
        p = p->next;
    }
    cout<< endl;
}
int main()
{
    List Q;
    initialize(Q);
    nhapDSSV(Q);
    xuatDSSV(Q);
}
