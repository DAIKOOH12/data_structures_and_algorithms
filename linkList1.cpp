#include <bits/stdc++.h>
using namespace std;
struct Node //Định nghĩa kiểu dữ node
{
    int data;
    Node *next;
};
struct LIST //Định nghĩa danh sách liên kết đơn
{
    Node *head;
    Node *tail;
};
void initList(LIST &l)  //Hàm khởi tạo danh sách liên kết đơn
{
    l.head=NULL;
    l.tail=NULL;
}
Node *createNode(int a) //Hàm khởi tạo 1 node trước khi thêm vào DSLK
{
    Node *p=new Node;
    if(p==NULL)
    {
        cout<<"Khong the khoi tao node";
        return NULL;
    }
    p->data=a;
    p->next=NULL;
    return p;
}
void insertHead(LIST &l,Node *p) //Hàm thêm 1 node vào đầu danh sách liên kết
{
    if(l.head==NULL)
    {
        l.head=l.tail=p; //Nếu DSLK rỗng thì gán con trỏ head và tail = p
    }
    else
    {
        p->next=l.head; //Dùng con trỏ next của p nối tới head của dslk
        l.head=p; //Gán lại giá trị cho head
    }
}
void insertLast(LIST &l,Node *p)
{
    if(l.head==NULL)
    {
        l.head=l.tail=p;
    }
    else
    {
        l.tail->next=p;
        l.tail=p;
    }
}
void nhapDSLK(LIST &l,int &n)
{
    cout<<"Nhap so luong phan tu: ";cin>>n;
    for(int i=1;i<=n;i++)
    {
        int b;
        cout<<"Nhap gia tri node: ";
        cin>>b;
        Node *p=createNode(b);
        insertLast(l,p);
    }
}
void xuatNode(Node *p)
{
    cout<<setw(10)<<p->data<<endl;
}
void xuatDSLK(LIST l)
{
    Node *p=l.head;
    cout<<setw(10)<<"Gia tri"<<endl;
    while(p!=NULL)
    {
        xuatNode(p);
        p=p->next;
    }
}
int main()
{
    int n;
    LIST l;
    initList(l);
    nhapDSLK(l,n);
    xuatDSLK(l);
}
