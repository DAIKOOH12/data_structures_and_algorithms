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
    cout<<"Nhap so luong phan tu: ";
    cin>>n;
    for(int i=1; i<=n; i++)
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
    cout<<setw(10)<<"Gia tri"<<endl;
    for(Node *k=l.head;k!=NULL;k=k->next)
    {
        xuatNode(k);
    }
}
void insertWithNode(LIST &l,Node *p)
{
    int x;
    xuatDSLK(l);
    cout<<"Nhap gia tri node q: ";
    cin>>x;
    Node *q=createNode(x);
    if(l.head->next==NULL&&q->data==l.head->data)
    {
        insertLast(l,p);
    }
    else
    {
        for(Node *k=l.head;k!=NULL;k=k->next)
        {
            if(q->data==k->data)
            {
                Node *g=k->next;
                p->next=g;
                k->next=p;
            }
        }
    }
}
int main()
{
    int chon;
    int n;
    LIST l;
    initList(l);
    do
    {
        system("cls");
        cout<<"===================MENU================="<<endl;
        cout<<"|| 1. Them phan tu vao dau danh sach  ||"<<endl;
        cout<<"|| 2. Them phan tu vao cuoi danh sach ||"<<endl;
        cout<<"|| 3. Them vao sau node q             ||"<<endl;
        cout<<"|| 4. Hien danh sach lien ket         ||"<<endl;
        cout<<"|| 0. Thoat                           ||"<<endl;
        cout<<"========================================"<<endl;
        {
            cout<<"Nhap lua chon cua ban: ";
            cin>>chon;
            switch(chon)
            {
            case 1:
                {
                    int a;
                    cout<<"Nhap gia tri node: ";cin>>a;
                    Node *p=createNode(a);
                    insertHead(l,p);
                    break;
                }
            case 2:
                {
                    int a;
                    cout<<"Nhap gia tri node: ";cin>>a;
                    Node *p=createNode(a);
                    insertLast(l,p);
                    break;
                }
            case 3:
                {
                    int x;
                    cout<<"Nhap gia tri node p: ";
                    cin>>x;
                    Node *p=createNode(x);
                    insertWithNode(l,p);
                    break;
                }
            case 4:
                {
                    xuatDSLK(l);
                     break;
                }
            }
        }
        system("pause");
    }while(chon!=0);
}
