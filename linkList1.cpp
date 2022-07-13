#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
    int data;
    Node *next;
};
typedef struct List
{
  Node *head;
  Node *tail;
};
void init(List &Q)
{
    Q.head=NULL;
    Q.tail=NULL;
}
Node* createNode(int a )
{
    Node *p=new Node;
    if(p==NULL)
    {
        cout<<"Khong tao duoc Node";
        exit(1);
    }
    p->data=a;
    p->next=NULL;
    return p;
}
void pushNodeFirst(List &Q,Node *p)
{
    if(!Q.head)
        Q.head=Q.tail=p;
    else
    {
        p->next=Q.head;
        Q.head = p;
    }
}
void pushNodeLast(List &Q,Node *p)
{
    if(!Q.head)
        Q.head=Q.tail=p;
    else{
        Q.tail->next=p;
        Q.tail=p;
    }
}
void nhapGiaTriNode(List &Q)
{
    int n;
    cout<<"Nhap so luong: ";cin>>n;
    for(int i=0;i<n;i++)
    {
        int a;cin>>a;
        Node *p= createNode(a);
        pushNodeFirst(Q,p);
    }
}
void xuat(Node *p){
	cout<<setw(10)<<p->data<<endl;
}
void xuatDS(List Q ){
    Node *p = Q.head;
    cout<<setw(10)<<"Gia tri"<<endl;
    while(p!=NULL){
        xuat(p);
        p = p->next;
    }
    cout<< endl;
}
int main()
{
      List Q;
      init(Q);
      nhapGiaTriNode(Q);
      xuatDS(Q);
}
