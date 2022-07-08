#include<bits/stdc++.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <ctime> 
#include <cstring>

using namespace std;
//=============Mat Hang=============
struct MatHang {
// 	char maMH[10];
 	int maMH;
 	char tenHang[20];
 	float giatien;
	int soluong;
};

struct NodeMH{
    struct NodeMH *Next;
    struct NodeMH *Prev;
    MatHang data;
};

struct DLishMH{
    NodeMH *head, *tail;
};

void Initializer( DLishMH &Q ){
    Q.head = Q.tail = NULL;
}

int IsemptyMH(DLishMH Q)
{
    if(Q.head==NULL)
    {
        return 1;
    }
    else return 0;
}

NodeMH *createNodeMH( MatHang x ){
    NodeMH *p = new NodeMH;
    if(p==NULL){ cout<<"Khong bo sung duoc!"<<endl; exit(1);}
    p->Next = NULL;
    p->Prev = NULL;
    p->data = x;
    return p;
}

void PushMH(DLishMH &Q, NodeMH *p ){
    if(!Q.head) 
		Q.head = Q.tail = p;
    else{
        Q.tail->Next = p;
        p->Prev = Q.tail;
        Q.tail = p;
    }
}

void nhapMH(MatHang &x){
//	cout<<"\n MaHang: ";fflush(stdin);cin>>x.maMH;
	cout<<"\n MaHang: ";cin>>x.maMH;
    cout<<"\n Ten hang: ";fflush(stdin);cin>>x.tenHang;
    cout<<"\n Gia tien: ";cin>>x.giatien;
	cout<<"\n So luong: ";cin>>x.soluong;
    cout<<endl;
}
void nhapDSMH(DLishMH &Q ){
    int n;
    NodeMH *p;
	MatHang x;
  	cout<<"Nhap so mat hang ban muon them vao trong DLish: ";
    cin>> n;
    while(n--){
    	nhapMH(x);
    	p = createNodeMH(x);	
        PushMH(Q,p);   
    }
}
void xuatMH(NodeMH *p){
	cout<<setw(10)<<p->data.maMH
		<<setw(16)<<p->data.tenHang
		<<setw(16)<<(long)p->data.giatien
		<<setw(16)<<p->data.soluong
		<<endl;
}

void xuatDSMH(DLishMH q ){
    NodeMH *p = q.head;
    cout<<setw(10)<<"Ma hang"
		<<setw(16)<<"Ten hang"
		<<setw(16)<<"Gia tien"
		<<setw(16)<<"So luong"
		<<endl;
    while(p!=NULL){
        xuatMH(p);
        p = p->Next;
    }
    cout<< endl;
}

void ghiFileMH(DLishMH Q)
 {
   FILE *f;
   char fileMH[20];
   printf("\nNhap ten file mat hang muon luu: ");fflush(stdin);gets(fileMH);
   f=fopen(fileMH,"w+b");
   for(NodeMH *p=Q.head;p!=NULL;p=p->Next)
   {
     fwrite(&p->data,sizeof(MatHang),1,f);
   }
   fclose(f);
 }
void hienFileMH(DLishMH &Q)
{
   	char fileMH[20];
	Initializer(Q);
	MatHang x;
    FILE*f;
    NodeMH *p=Q.head;
    char maMH[30];
    char tenHang[30];
    float giatien;
    printf("\nNhap ten file mat hang muon mo: ");fflush(stdin);gets(fileMH);
   	f=fopen(fileMH,"r+b");
    if(f==NULL)
   {
		printf("\nLoi mo tep.");
		return;
   }
   while(true)
   {
     fread(&x,sizeof(MatHang),1,f);
     if(feof(f)) break;
     p=createNodeMH(x);
     PushMH(Q,p);
   }
   fclose(f);
   printf("\nDanh sach trong file MatHang.txt la: \n");
   xuatDSMH(Q);

}
//them 1 mat hang vao dau/cuoi/sau maMH k
void add_dau(DLishMH &Q)
{
	NodeMH *p;
	MatHang x;
	nhapMH(x);
	p = createNodeMH(x);	
    if(!Q.head) 
		Q.head = Q.tail = p;
    else{
        Q.head->Prev = p;
        p->Next = Q.head;
        Q.head = p;
    }
}
void add_cuoi(DLishMH Q)
{
	NodeMH *p;
	MatHang x;
	nhapMH(x);
	p = createNodeMH(x);	
    PushMH(Q,p); 
}

//tim mat hang co gia ban cao nhat
void search_mh_giaban_max(DLishMH &Q)
{
	NodeMH *p=Q.head;
	NodeMH *max=Q.head;
	while(p!=NULL){
		if(p->data.giatien>max->data.giatien){
			max=p;
		}
		p=p->Next;
	}
	cout<<setw(10)<<"Ma hang"
		<<setw(16)<<"Ten hang"
		<<setw(16)<<"Gia tien"
		<<setw(16)<<"So luong"
		<<endl;
	xuatMH(max);
}
//xoa thong tin mat hang co ma mat hang tuong ung
void delete_mh_mamh_k(DLishMH &Q)
{
	if(IsemptyMH(Q)==1){
		cout<<"Danh sach khong co mat hang nao"<<endl;
	}else{
		int maMH;
		cout<<"Nhap ma mat hang can xoa: ";cin>>maMH;
		NodeMH *p=Q.head;
		NodeMH *q=Q.tail;
		if(p->data.maMH==maMH){
			Q.head=p->Next;
			Q.head->Prev = NULL;
		}else{
			if(q->data.maMH==maMH){
				Q.tail=q->Prev;
				Q.tail->Next = NULL;
			}else{
				while(p!=NULL){
					if(p->data.maMH==maMH){
						p->Next->Prev=p->Prev;
						p->Prev->Next=p->Next;
					}
					p=p->Next;
				}
			}
		} 
	}
}
//sap xep danh sach mat hang theo gia ban
void sapxep_mh_giaban(DLishMH &Q)
{
	NodeMH *p = Q.head, *q;
	while(p!=NULL)
	{
		q=p->Next;
		while(q!=NULL)
		{
			if(p->data.giatien>q->data.giatien)
				swap(p->data,q->data);
			q=q->Next;
		}
		p=p->Next;
	}
}
//sap xep mat hang theo ten tu A->Z
void sapxep_mh_ten(DLishMH &Q)
{
	NodeMH *p = Q.head, *q;
	while(p!=NULL)
	{
		q=p->Next;
		while(q!=NULL)
		{
			if(strcmp(p->data.tenHang,q->data.tenHang)>0)
				swap(p->data,q->data);
			q=q->Next;
		}
		p=p->Next;
	}
}

//=============Nhan Vien=============
struct NhanVien{
// 	char maNV[10];
 	int maNV;
 	char tenNV[20];
	char gioiTinh[10];
	int soNamVaoLam;
	int soBuoiLam;
	int soBuoiTangCa;
	int soBuoiNghi;
	float hsl;
	float luong;
};


struct NodeNV{
    struct NodeNV *Next;
    struct NodeNV *Prev;
    NhanVien data;
};

struct DLishNV{
    NodeNV *head, *tail;
};

void InitializerNV( DLishNV &Q ){
    Q.head = Q.tail = NULL;
}

int IsemptyNV(DLishNV Q)
{
    if(Q.head==NULL)
    {
        return 1;
    }
    else return 0;
}

NodeNV *createNodeNV( NhanVien x ){
    NodeNV *p = new NodeNV;
    if(p==NULL){ cout<<"Khong bo sung duoc!"<<endl; exit(1);}
    p->Next = NULL;
    p->Prev = NULL;
    p->data = x;
    return p;
}

void PushNV(DLishNV &Q, NodeNV *p ){
    if(!Q.head) 
		Q.head = Q.tail = p;
    else{
        Q.tail->Next = p;
        p->Prev = Q.tail;
        Q.tail = p;
    }
}

void nhapNV(NhanVien &x){
//	cout<<"\n MaHang: ";fflush(stdin);cin>>x.maMH;
	cout<<"\n Ma nhan vien: ";cin>>x.maNV;
    cout<<"\n Ten nhan vien: ";fflush(stdin);cin>>x.tenNV;
    cout<<"\n Gioi tinh: ";cin>>x.gioiTinh;
    cout<<"\n So nam vao lam: ";cin>>x.soNamVaoLam;
    cout<<"\n So buoi lam: ";cin>>x.soBuoiLam;
    cout<<"\n So buoi tang ca: ";cin>>x.soBuoiTangCa;
    cout<<"\n So buoi nghi: ";cin>>x.soBuoiNghi;
    cout<<"\n He so luong: ";cin>>x.hsl;
	x.luong=(x.soBuoiLam + x.soBuoiTangCa*2 + x.soBuoiNghi)* x.hsl;
    cout<<endl;

}
void nhapDSNV(DLishNV &Q ){
    int n;
    NodeNV *p;
	NhanVien x;
  	cout<<"Nhap so nhan vien ban muon them vao trong DLish: ";
    cin>> n;
    while(n--){
    	nhapNV(x);
    	p = createNodeNV(x);	
        PushNV(Q,p);   
    }
}
void xuatNV(NodeNV *p){
	cout<<setw(10)<<p->data.maNV
		<<setw(15)<<p->data.tenNV
		<<setw(15)<<p->data.gioiTinh
		<<setw(16)<<p->data.soNamVaoLam
		<<setw(16)<<p->data.soBuoiLam
		<<setw(17)<<p->data.soBuoiTangCa
		<<setw(16)<<p->data.soBuoiNghi
		<<setw(13)<<p->data.hsl
		<<setw(16)<<(long)p->data.luong
		<<endl;
}
void xuatDS(){
		cout<<setw(10)<<"Ma nv"
		<<setw(15)<<"Ten nv"
		<<setw(15)<<"Gioi tinh"
		<<setw(16)<<"So nam vao lam"
		<<setw(16)<<"so buoi lam"
		<<setw(17)<<"So buoi tang ca"
		<<setw(16)<<"So buoi nghi"
		<<setw(13)<<"Hsl"
		<<setw(16)<<"Luong"
		<<endl;
}
void xuatDSNV(DLishNV q ){
    NodeNV *p = q.head;
    xuatDS();
    while(p!=NULL){
        xuatNV(p);
        p = p->Next;
    }
    cout<< endl;
}

void ghiFileNV(DLishNV Q)
 {
   FILE *f;
   char fileNV[20];
   printf("\nNhap ten file san pham muon luu: ");fflush(stdin);gets(fileNV);
   f=fopen(fileNV,"w+b");
   for(NodeNV *p=Q.head;p!=NULL;p=p->Next)
   {
     fwrite(&p->data,sizeof(NhanVien),1,f);
   }
   fclose(f);
 }
void hienFileNV(DLishNV &Q)
{

	InitializerNV(Q);
	NhanVien x;
    FILE*f;
    NodeNV *p=Q.head;
	char fileNV[20];
    printf("\nNhap ten file san pham muon mo: ");fflush(stdin);gets(fileNV);
   	f=fopen(fileNV,"r+b");
    if(f==NULL)
   {
		printf("\nLoi mo tep.");
		return;
   }
   while(true)
   {
     fread(&x,sizeof(NhanVien),1,f);
     if(feof(f)) break;
     p=createNodeNV(x);
     PushNV(Q,p);
   }
   fclose(f);
   printf("\nDanh sach trong file NhanVien.txt la: \n");
   xuatDSNV(Q);

}
//them 1 nhan vien vao dau/cuoi/sau maMH k
void add_dauNV(DLishNV &Q)
{
	NodeNV *p;
	NhanVien x;
	nhapNV(x);
	p = createNodeNV(x);	
    if(!Q.head) 
		Q.head = Q.tail = p;
    else{
        Q.head->Prev = p;
        p->Next = Q.head;
        Q.head = p;
    }
}
void add_cuoiNV(DLishNV Q)
{
	NodeNV *p;
	NhanVien x;
	nhapNV(x);
	p = createNodeNV(x);	
    PushNV(Q,p); 
}
//xoa 
void delete_nv_ma_k(DLishNV &Q){
    if(IsemptyNV(Q)==1){
		cout<<"Danh sach khong co nhan vien nao"<<endl;
	}else{
		int manv;
		cout<<"Nhap ma nhan vien can xoa: ";cin>>manv;
		NodeNV *p=Q.head;
		NodeNV *q=Q.tail;
		if(p->data.maNV==manv){
			Q.head=p->Next;
			Q.head->Prev = NULL;
		}else{
			if(q->data.maNV==manv){
				Q.tail=q->Prev;
				Q.tail->Next = NULL;
			}else{
				while(p!=NULL){
					if(p->data.maNV==manv){
						p->Next->Prev=p->Prev;
						p->Prev->Next=p->Next;
					}
					p=p->Next;
				}
			}
		} 
	}
}

//tim kiem nhan vien nghi so buoi nhieu nhat
void timkiem_nv_sobuoinghi_max(DLishNV &Q){
	NodeNV *p=Q.head;
	NodeNV *max=Q.head;
	while(p!=NULL){
		if(p->data.soBuoiNghi>max->data.soBuoiNghi){
			max=p;
		}
		p=p->Next;
	}
	xuatDS();
	xuatNV(max);
}
//Tim nhan vien co luong cao nhat
void timkiem_nv_luong_max(DLishNV &Q){
	NodeNV *p=Q.head;
	NodeNV *max=Q.head;
	while(p!=NULL){
		if(p->data.luong>max->data.luong){
			max=p;
		}
		p=p->Next;
	}
	xuatDS();
	xuatNV(max);
}
//tim nhan vien theo ma nhan vien
void timkiem_nv_ma_k(DLishNV &Q){
	int manv;
	cout<<"Nhap ma nhan vien tim kiem: ";cin>>manv;
	NodeNV *p=Q.head;
	xuatDS();
	while(p!=NULL){
		if(p->data.maNV==manv){
			xuatNV(p);
		}
		p=p->Next;
	}
}
//tim kiem nhan vien co so buoi tang ca nhieu nhat
void timkiem_nv_sobuoitangca_max(DLishNV &Q){
	NodeNV *p=Q.head;
	NodeNV *max=Q.head;
	while(p!=NULL){
		if(p->data.soBuoiTangCa>max->data.soBuoiTangCa){
			max=p;
		}
		p=p->Next;
	}
	xuatDS();
	xuatNV(max);
}
//sap xep danh sach nhan vien theo luong
void sapxep_nv_luong(DLishNV &Q)
{
	NodeNV *p = Q.head, *q;
	while(p!=NULL)
	{
		q=p->Next;
		while(q!=NULL)
		{
			if(p->data.luong>q->data.luong)
				swap(p->data,q->data);
			q=q->Next;
		}
		p=p->Next;
	}
}
//sap xep nhan vien theo so ngay nghi
void sapxep_nv_songaynghi(DLishNV &Q)
{
	NodeNV *p = Q.head, *q;
	while(p!=NULL)
	{
		q=p->Next;
		while(q!=NULL)
		{
			if(p->data.soBuoiNghi>q->data.soBuoiNghi)
				swap(p->data,q->data);
			q=q->Next;
		}
		p=p->Next;
	}
}
//tong luong cua tat ca cac nhan vien
float tong_nv_luong(DLishNV &Q){
	float tong = 0;
	NodeNV *p = Q.head;
	while(p!=NULL){
		tong +=p->data.luong;
		p=p->Next;
	}
	return tong;
}
//tong so buoi tang ca cua tat ca cac nhan vien
int tong_nv_buoitangca(DLishNV &Q){
	int buoitangca = 0;
	NodeNV *p = Q.head;
	while(p!=NULL){
		buoitangca +=p->data.soBuoiTangCa;
		p=p->Next;
	}
	return buoitangca;
}
//tong so buoi nghi cua tat ca cac nhan vien
int tong_nv_buoinghi(DLishNV &Q){
	int buoinghi = 0;
	NodeNV *p = Q.head;
	while(p!=NULL){
		buoinghi +=p->data.soBuoiNghi;
		p=p->Next;
	}
	return buoinghi;
}
//thong ke cac nhan vien co so nam vao lam trong quan lon hon k
void thongke_nv_namvaolam_k(DLishNV &Q){
	int namvaolam;
	cout<<"Nhap moc nam vao lam: ";cin>>namvaolam;
	cout<<"Danh sach nhan vien co nam vao lam lon hon "<<namvaolam<<" nam: \n";
	NodeNV *p = Q.head;
	xuatDS();
	while(p!=NULL){
		if(p->data.soNamVaoLam>namvaolam){
			xuatNV(p);
		}
		p=p->Next;
	}
}
//thong ke cac nhan vien co so buoi nghi lon hon k
void thongke_nv_sobuoinghi_k(DLishNV &Q){
	int k;
	cout<<"Nhap so buoi nghi: ";cin>>k;
	cout<<"Danh sach nhan vien co so buoi nghi lon hon "<<k<<" la: \n";
	NodeNV *p = Q.head;
	xuatDS();
	while(p!=NULL){
		if(p->data.soBuoiNghi>k){
			xuatNV(p);
		}
		p=p->Next;
	}
}
//thong ke nhan vien co gioi tinh la nam
void thongke_nv_gioitinh_nam(DLishNV &Q){

	cout<<"Danh sach nhan vien co gioi tinh nam la: \n";
	NodeNV *p = Q.head;
	xuatDS();
	while(p!=NULL){
		if(strcmp(p->data.gioiTinh, "nam")==0){
			xuatNV(p);
		}
		p=p->Next;
	}
}
//lietke nhan vien co luong lon hon x
void thongke_nv_luong_x(DLishNV &Q){
	float x;
	cout<<"Nhap so luong x: ";cin>>x;
	cout<<"Danh sach nhan vien co luong lon hon "<<x<<" la: \n";
	NodeNV *p = Q.head;
	xuatDS();
	while(p!=NULL){
		if(p->data.luong>x){
			xuatNV(p);
		}
		p=p->Next;
	}
}

//-------------- Hóa đơn ----------------
struct HoaDon {
// 	char maMH[10];
 	int Mahd;
 	char Ngaylap[10];
 	float Giatien;
	int Soluong;
	char Tenkh[30];
};

struct NodeHD{
    struct NodeHD *Next;
    struct NodeHD *Prev;
    HoaDon data;
};

struct DLishHD{
    NodeHD *head, *tail;
};

void InitializerHD( DLishHD &E ){
    E.head = E.tail = NULL;
}

int IsemptyHD(DLishHD E)
{
    if(E.head==NULL)
    {
        return 1;
    }
    else return 0;
}

NodeHD *createNodeHD( HoaDon x ){
    NodeHD *p = new NodeHD;
    if(p==NULL){ cout<<"Khong bo sung duoc!"<<endl; exit(1);}
    p->Next = NULL;
    p->Prev = NULL;
    p->data = x;
    return p;
}

void PushHD(DLishHD &E, NodeHD *p ){
    if(!E.head) 
		E.head = E.tail = p;
    else{
        E.tail->Next = p;
        p->Prev = E.tail;
        E.tail = p;
    }
}

void nhapHD(HoaDon &x)
{
	// time_t baygio = time(0); 
	// tm *ltm = localtime(&baygio);
	 
	// int ngay = ltm->tm_mday;
	// int thang = 1 + ltm->tm_mon;
	// int nam = 1900 + ltm->tm_year;
	// std::string d = std::to_string(ngay);
	// std::string m = std::to_string(thang);
	// std::string y = std::to_string(nam);
	// string str = d+"/"+m+"/"+y;
	// x.Ngaylap = str;
	cout<<"\n Ma hoa don: ";cin>>x.Mahd;
	cout<<"\n Ngay lap: ";fflush(stdin);cin>>x.Ngaylap;
    cout<<"\n Gia tien: ";cin>>x.Giatien;
	cout<<"\n So luong: ";cin>>x.Soluong;
	cout<<"\n Ten khach hang: ";fflush(stdin);cin>>x.Tenkh;
    cout<<endl;
}
void nhapDSHD(DLishHD &Q ){
    int n;
    NodeHD *p;
	HoaDon x;
  	cout<<"Nhap so hoa don ban muon them vao trong DLish: ";
    cin>> n;
    while(n--){
    	nhapHD(x);
    	p = createNodeHD(x);	
        PushHD(Q,p);   
    }
}
void xuatHD(NodeHD *p){
	cout<<setw(10)<<p->data.Mahd
		<<setw(16)<<p->data.Ngaylap
		<<setw(16)<<(long)p->data.Giatien
		<<setw(16)<<p->data.Soluong
		<<setw(16)<<p->data.Tenkh
		<<endl;
}

void xuatDSHD(DLishHD q ){
    NodeHD *p = q.head;
    cout<<setw(10)<<"Ma hoa don"
		<<setw(16)<<"Ngay lap"
		<<setw(16)<<"Gia tien"
		<<setw(16)<<"So luong"
		<<setw(16)<<"Ten kh"
		<<endl;
    while(p!=NULL){
        xuatHD(p);
        p = p->Next;
    }
    cout<< endl;
}
void xuatHD2(){
	cout<<setw(10)<<"Ma hoa don"
		<<setw(16)<<"Ngay lap"
		<<setw(16)<<"Gia tien"
		<<setw(16)<<"So luong"
		<<setw(16)<<"Ten kh"
		<<endl;
}
void ghiFileHD(DLishHD E)
{
	FILE *f;
	char fileHD[20];
	printf("\nNhap ten file hoa don muon luu: ");fflush(stdin);gets(fileHD);
	f=fopen(fileHD,"w+b");
	for(NodeHD *p=E.head;p!=NULL;p=p->Next)
	{
		fwrite(&p->data,sizeof(HoaDon),1,f);
	}
	fclose(f);
}
void hienFileHD(DLishHD &E)
{
	char fileHD[20];
	InitializerHD(E);
	HoaDon x;
	FILE*f;
	NodeHD *p=E.head;

	printf("\nNhap ten file mat hang muon mo: ");fflush(stdin);gets(fileHD);
	f=fopen(fileHD,"r+b");
	if(f==NULL)
	{
		printf("\nLoi mo tep.");
		return;
	}
	while(true)
	{
		fread(&x,sizeof(HoaDon),1,f);
		if(feof(f)) break;
		p=createNodeHD(x);
		PushHD(E,p);
	}
	fclose(f);
	printf("\nDanh sach trong file hoa don la: \n");
	xuatDSHD(E);

}
//thêm vào cuối danh sách hóa đơn
void add_cuoiHD(DLishHD &E){
	NodeHD *p;
	HoaDon x;
	nhapHD(x);
	p = createNodeHD(x);	
    PushHD(E,p);
} 
//add trước
// void add_truocHD(DLishHD &E){
// 	NodeHD *p;
// 	NodeHD *q;
// 	HoaDon x;
// 	int dem=0;
// 	cout<<"Nhap hoa don moi:"<<endl;
// 	nhapHD(x);
// 	p = createNodeHD(x);
// 	q=E.head;	
// 	int n; cout<<"Nhap ma hoa don k: ";cin>>n;
// 	while (q!=NULL)
// 	{
// 		if (E.head->data.Mahd==n)
// 		{
// 			dem++;
// 			p->Next=E.head;
// 			E.head->Prev=p;
// 			E.head=p;
// 		}else if (q->data.Mahd==n)
// 		{
// 			dem++;
// 			p->Prev=q->Prev;
// 			p->Next=q;
// 			q->Prev->Next=p;
// 			q->Prev=p;
// 		}
// 		q=q->Next;
// 	}
// 	if (dem==0)
// 	{
// 		cout<<"Khong tim thay vi tri can chen!"<<endl;
// 	}
// }
//add giữa
// void add_cuoiHD(DLishHD &E){
// 	NodeHD *p;
// 	NodeHD *q;
// 	HoaDon x;
// 	int dem=0;
// 	cout<<"Nhap hoa don moi:"<<endl;
// 	nhapHD(x);
// 	p = createNodeHD(x);
// 	q=E.head;	
// 	int n; cout<<"Nhap ma hoa don cua phan tu truoc vi tri can chen: ";cin>>n;
// 	while (q!=NULL)
// 	{
// 		if (q->data.Mahd==n)
// 		{
// 			dem++;
// 			if (q==E.tail)
// 			{
// 				PushHD(E, p);
// 			}else{
// 				p->Next=q->Next;
// 				p->Prev=q;
// 				q->Next->Prev=p;
// 				q->Next=p;
// 			}
// 		}
// 		q=q->Next;
// 	}
// 	if (dem==0)
// 	{
// 		cout<<"Khong tim thay vi tri can chen!"<<endl;
// 	}
// }
//xoa hoa don theo ma k
void delete_hd_mahd_k(DLishHD &E)
{
	if(IsemptyHD(E)==1){
		cout<<"Danh sach khong co hoa don nao"<<endl;
	}else{
		int Mahd;
		cout<<"Nhap ma hoa don can xoa: ";cin>>Mahd;
		NodeHD *p=E.head;
		NodeHD *q=E.tail;
		if(p->data.Mahd==Mahd){
			E.head=p->Next;
			E.head->Prev = NULL;
		}else{
			if(q->data.Mahd==Mahd){
				E.tail=q->Prev;
				E.tail->Next = NULL;
			}else{
				while(p!=NULL){
					if(p->data.Mahd==Mahd){
						p->Next->Prev=p->Prev;
						p->Prev->Next=p->Next;
					}
					p=p->Next;
				}
			}
		} 
	}
}
//sắp xếp danh sách theo thời gian
void sapxep_hd_ngaylap(DLishHD &E)
{
	NodeHD *p = E.head, *q;
	while(p!=NULL)
	{
		q=p->Next;
		while(q!=NULL)
		{
			if(strcmp(p->data.Ngaylap,q->data.Ngaylap)>0)
				swap(p->data,q->data);
			q=q->Next;
		}
		p=p->Next;
	}
}
//sắp xếp danh sách theo giá tiền
void sapxep_hd_gaitien(DLishHD &E)
{
	NodeHD *p = E.head, *q;
	while(p!=NULL)
	{
		q=p->Next;
		while(q!=NULL)
		{
			if(p->data.Giatien>q->data.Giatien)
				swap(p->data,q->data);
			q=q->Next;
		}
		p=p->Next;
	}
}
//Tim kiem thong tin hoa don theo ma k
void timkiem_hd_ma_k(DLishHD &E){
	int mahd;
	cout<<"Nhap ma hoa don tim kiem: ";cin>>mahd;
	NodeHD *p=E.head;
	xuatHD2();
	while(p!=NULL){
		if(p->data.Mahd==mahd){
			xuatHD(p);
		}
		p=p->Next;
	}
}
//Tim kiem thong tin hoa don theo ten khach hang
void timkiem_hd_tenkh(DLishHD &E){
	char tenkh[30];
	cout<<"Nhap ten khach hang can tim kiem: ";cin>>tenkh;
	NodeHD *p=E.head;
	xuatHD2();
	while(p!=NULL){
		if(strstr( p->data.Tenkh, tenkh )!= NULL){
			xuatHD(p);
		}
		p=p->Next;
	}
}
//Tinh tong so luong da ban theo ngay k
void tong_hd_soluong_ngay_k(DLishHD E){
	int tongsoluong = 0;
	char ngay[11];
	cout<<"Nhap ngay(dd/mm/yyyy) muon tinh tong so luong: ";cin>>ngay;
	NodeHD *p = E.head;
	while(p!=NULL){
		// cout<<p->data.Ngaylap<<" : "<<ngay<<endl;
		if(strcmp(p->data.Ngaylap,ngay)==0){
			tongsoluong +=p->data.Soluong;
		}
		p=p->Next;
	}
	cout<<"Tong so luong trong ngay "<<ngay<<" la: "<<tongsoluong<<endl;
}
//Tinh tong gia tien của tất cả hóa đơn
float tong_hd_giatien(DLishHD E){
	int tonggiatien = 0;
	NodeHD *p = E.head;
	while(p!=NULL){
		tonggiatien +=p->data.Giatien;
		p=p->Next;
	}
	return tonggiatien;
}
//Thong ke nhung hoa don co so luong tren k
void thongke_hd_soluong_tren_k(DLishHD E){
	int soluong;
	cout<<"Nhap moc so luong: ";cin>>soluong;
	cout<<"Danh sach hoa don co soluong lon hon "<<soluong<<" la: \n";
	NodeHD *p = E.head;
	xuatHD2();
	while(p!=NULL){
		if(p->data.Soluong>=soluong){
			xuatHD(p);
		}
		p=p->Next;
	}
}
//Thong ke nhung hoa don co gia tien tren k
void thongke_hd_giatien_tren_k(DLishHD E){
	int gia;
	cout<<"Nhap moc gia tien: ";cin>>gia;
	cout<<"Danh sach hoa don co soluong lon hon "<<gia<<" la: \n";
	NodeHD *p = E.head;
	xuatHD2();
	while(p!=NULL){
		if(p->data.Giatien>=gia){
			xuatHD(p);
		}
		p=p->Next;
	}
}
//Thong ke ten nhung khach hang
void thongke_hd_tenkh(DLishHD E){

	NodeHD *p = E.head;
	cout<<setw(10)<<"Ten khach hang"<<endl;
	while(p!=NULL){
		cout<<setw(10)<<p->data.Tenkh<<endl;
		p=p->Next;
	}
}
//hiện danh sách những hóa đơn có ngày nhập từ bàn phím 
void HoaDon_NgayLap(DLishHD E){
	NodeHD *p = E.head, *q;
	if (E.head==NULL)
	{
		cout<<"Danh sach rong";
	}else{
		char ngaylap[30];
		cout<<"Nhap ngay lap can tim kiem: ";cin>>ngaylap;
		xuatHD2();
		while(p!=NULL){
			if(strstr( p->data.Ngaylap, ngaylap )!= NULL){
				xuatHD(p);
			}
			p=p->Next;
		}
	}
	
	
}
//xắp sếp hóa đơn theo tên khách hàng
void sapxep_hd_ten(DLishHD &E)
{
	NodeHD *p = E.head, *q;
	while(p!=NULL)
	{
		q=p->Next;
		while(q!=NULL)
		{
			if(strcmp(p->data.Tenkh,q->data.Tenkh)>0)
				swap(p->data,q->data);
			q=q->Next;
		}
		p=p->Next;
	}
}
//18
void sua(DLishHD &E){
	if(IsemptyHD(E)==1){
		cout<<"Danh sach khong co hoa don nao"<<endl;
	}else{
		NodeHD *p;
		p=E.head;
		int Mahd;
		cout<<"Nhap ma hoa don can sua: ";cin>>Mahd;
		while(p!=NULL){
			if (p->data.Mahd==Mahd)
			{
				cout<<"\n Ngay lap moi: ";fflush(stdin);cin>>p->data.Ngaylap;
				cout<<"\n Gia tien moi: ";cin>>p->data.Giatien;
				cout<<"\n So luong moi: ";cin>>p->data.Soluong;
				cout<<"\n Ten khach hang moi: ";fflush(stdin);cin>>p->data.Tenkh;
			}
			p=p->Next;
		}
	}
}
//menu
void menu(){
	int i, k;
	MatHang x;
	NodeMH *p;
	DLishMH Q;
	Initializer(Q);

	NhanVien y;
	NodeNV *q;
	DLishNV H;
	InitializerNV(H);

	HoaDon Z;
	
	DLishHD E;
	InitializerHD(E);
	while(true){
		cout<<"==============MENU================="
	    <<"\n0.Thoat."
	    <<"\n1.Quan ly DS Mat Hang."
	    <<"\n2.Quan ly DS Nhan Vien."
		<<"\n3.Quan ly DS Hoa Don."
	    <<"\nBan chon ? ";
	    cin>> i;
	    
	    if(i>=0&&i<=3) cout<<"Hay nhap dung chi so!"<<endl;
		if(i==0)break;
		else if(i==1){
			do{
				printf("\n=================MENU=================");
				printf("\n0.Thoat");
				printf("\n1.Nhap danh sach mat hang.");
				printf("\n2.Xuat danh sach mat hang.");
				printf("\n3.Luu lai danh sach mat hang.");
				printf("\n4.Hien danh sach mat hang da luu.");
				printf("\n5.Bo sung them mat hang vao dau danh sach.");
				printf("\n6.Tim mat hang co gia ban cao nhat");
				printf("\n7.Xoa thong tin mat hang theo ma.");
				printf("\n8.Sap xep danh sach mat hang theo gia ban.");
				printf("\n9.Sap xep mat hang theo ten tu A->Z.");
				printf("\n=================END=================");
		
				printf("\nMoi ban chon: ");scanf("%d",&k);
				system("cls");
		
				switch(k){
					case 0: break;
					case 1:nhapDSMH(Q);
		       			getch();
		       			break;
					case 2:xuatDSMH(Q);
						getch();
						break;
					case 3:ghiFileMH(Q);
						cout<<"Ghi file thanh cong"<<endl;
						getch();
						break;
					case 4: hienFileMH(Q);
		  		 		getch();
		        		break;
		  			case 5: add_dau(Q);
		          		getch();
		          		break;
		  			case 6: search_mh_giaban_max(Q);
		          		getch();
		          		break;      
		  			case 7: delete_mh_mamh_k(Q);
		  		  		getch();
		  		  		break;
		  			case 8: sapxep_mh_giaban(Q);
		  		  		cout<<"Danh sach mat hang sau khi sap xep la: \n";
		  		  		xuatDSMH(Q);
		  		  		getch();
		  		  		break;
		  			case 9: sapxep_mh_ten(Q);
		  		  		cout<<"Danh sach mat hang sau khi sap xep la: \n";
		  		  		xuatDSMH(Q);
		  		  		getch();
		  		  		break;													  
		   		default:
				     	printf("\nLua chon khong hop le. Nhap lai");
				     	break;
		 		}

			}while(k!=0);
		  
		}else if(i==2){
			do{
				 printf("\n=================MENU=================");
				 printf("\n0.Thoat");
				 printf("\n1.Nhap danh sach nhan vien.");
				 printf("\n2.Xuat danh sach nhan vien.");
				 printf("\n3.Luu lai danh sach nhan vien.");
				 printf("\n4.Hien danh sach nhan vien da luu.");
				 printf("\n5.Bo sung them nhan vien vao cuoi danh sach.");
				 printf("\n6.Xoa thong tin nhan vien theo ma k");
				 printf("\n7.Tim nhan vien co so buoi nghi nhieu nhat.");
				 printf("\n8.Tim nhan vien co luong cao nhat.");
				 printf("\n9.Tim nhan vien theo ma nhan vien.");
				 printf("\n10.Tim nhan vien co so buoi tang ca nhieu nhat.");
				 printf("\n11.Sap xep danh sach nhan vien theo luong.");
				 printf("\n12.Sap xep danh sach nhan vien theo so ngay nghi.");
				 printf("\n13.Tong luong cua tat ca cac nhan vien.");
				 printf("\n14.Tong so buoi tang ca cua tat ca nhan vien.");
				 printf("\n15.Tong so buoi nghi cua tat ca nhan vien.");
				 printf("\n16.Thong ke nhan vien co so nam lam trong quan lon hon k.");
				 printf("\n17.Thong ke cac nhan vien co so buoi nghi lon hon k.");
				 printf("\n18.Thong ke cac nhan vien co gioi tinh la nam.");
				 printf("\n19.Liet ke cac nhan vien co luong lon hon x.");
				 printf("\n=================END=================");
		 
				 printf("\nMoi ban chon: ");scanf("%d",&k);
				 system("cls");
		 
				 switch(k){
					case 0: break;
					case 1:nhapDSNV(H);
		       			getch();
		       			break;
					case 2:
						xuatDSNV(H);
						getch();
						break;
					case 3:ghiFileNV(H);
						cout<<"Ghi file thanh cong"<<endl;
						getch();
						break;
					case 4: hienFileNV(H);
		  		 		getch();
		        		break;
		  			case 5: add_cuoiNV(H);
		          		getch();
		          		break;
		  			case 6: delete_nv_ma_k(H);
		          		getch();
		          		break;      
		  			case 7: timkiem_nv_sobuoinghi_max(H);
		  		  		getch();
		  		  		break;
		  			case 8: timkiem_nv_luong_max(H);
		  		  		getch();
		  		  		break;
		  			case 9: timkiem_nv_ma_k(H);
		  		  		getch();
		  		  		break;	
					case 10: timkiem_nv_sobuoitangca_max(H);
		  		  		getch();
		  		  		break;
					case 11: sapxep_nv_luong(H);
						cout<<"Danh sach nhan vien sau khi sap xep theo luong la: "<<endl;
						xuatDSNV(H);
		  		  		getch();
		  		  		break;
					case 12: sapxep_nv_songaynghi(H);
						cout<<"Danh sach nhan vien sau khi sap xep theo so ngay nghi la: "<<endl;
						xuatDSNV(H);
		  		  		getch();
		  		  		break;
					case 13: cout<<"Tong luong cua tat ca nhan vien la: "<<tong_nv_luong(H)<<endl;
		  		  		getch();
		  		  		break;
					case 14: cout<<"Tong so buoi tang ca cua nhan vien la: "<<tong_nv_buoitangca(H)<<endl;
		  		  		getch();
		  		  		break;
					case 15: cout<<"Tong so buoi nghi cua nhan vien la: "<<tong_nv_buoinghi(H)<<endl;
		  		  		getch();
		  		  		break;
					case 16: thongke_nv_namvaolam_k(H);
		  		  		getch();
		  		  		break;
					case 17: thongke_nv_sobuoinghi_k(H);
		  		  		getch();
		  		  		break;
					case 18: thongke_nv_gioitinh_nam(H);
		  		  		getch();
		  		  		break;
					case 19: thongke_nv_luong_x(H);
		  		  		getch();
		  		  		break;
																	  
		   		default:
				     	printf("\nLua chon khong hop le. Nhap lai");
				     	break;
		 		}

			}while(k!=0);
		}else if(i==3){
			do{
				printf("\n=================MENU=================");
				printf("\n0.Thoat");
				printf("\n1.Nhap danh sach hoa don.");
				printf("\n2.Xuat danh sach hoa don.");
				printf("\n3.Luu lai danh sach hoa don.");
				printf("\n4.Hien danh sach hoa don da luu.");
				printf("\n5.Bo sung them hoa don vao cuoi danh sach.");
				printf("\n6.Xoa thong tin hoa don theo ma.");
				printf("\n7.Sap xep thong tin hoa don theo ngay lap.");
				printf("\n8.Sap xep thong tin hoa don theo gia tien.");
				printf("\n9.Tim kiem thong tin hoa don theo ma k.");
				printf("\n10.Tim kiem thong tin hoa don theo ten khach hang.");
				printf("\n11.Tinh tong so luong da ban theo ngay k.");
				printf("\n12.Tinh tong gia tien cua tat ca hoa don.");
				printf("\n13.Thong ke nhung hoa don co so luong tren k.");
				printf("\n14.Thong ke nhung hoa don co gia tien tren k.");
				printf("\n15.Thong ke ten nhung khach hang.");
				printf("\n16.Hien hoa don theo ngay.");
				printf("\n17.Sap xep hoa don theo ten khach  hang.");
				printf("\n18.Sua.");
				printf("\n=================END=================");
		
				printf("\nMoi ban chon: ");scanf("%d",&k);
				system("cls");
		 
				switch(k){
					case 0: break;
					case 1:nhapDSHD(E);
		       			getch();
		       			break;
					case 2:xuatDSHD(E);
						getch();
						break;
					case 3:ghiFileHD(E);
						cout<<"Ghi file thanh cong"<<endl;
						getch();
						break;
					case 4: hienFileHD(E);
		  		 		getch();
		        		break;
		  			case 5: add_cuoiHD(E);
		          		getch();
		          		break;
					case 6: delete_hd_mahd_k(E);
						cout<<"Danh sach hoa don sau khi xoa"<<endl;
						xuatDSHD(E);
		  		  		getch();
		  		  		break;	
					case 7: sapxep_hd_ngaylap(E);
						cout<<"Danh sach hoa don sau khi sap xep"<<endl;
						xuatDSHD(E);
		  		  		getch();
		  		  		break;	
					case 8: sapxep_hd_gaitien(E);
						cout<<"Danh sach hoa don sau khi sap xep"<<endl;
						xuatDSHD(E);
		  		  		getch();
		  		  		break;
					case 9: timkiem_hd_ma_k(E);
		  		 		getch();
		        		break;
					case 10: timkiem_hd_tenkh(E);
		  		 		getch();
		        		break;
					case 11: tong_hd_soluong_ngay_k(E);
		  		 		getch();
		        		break;
					case 12: cout<<"Tong so tien cua tat ca hoa don la: "<<tong_hd_giatien(E)<<endl;
		  		 		getch();
		        		break;
					case 13: thongke_hd_soluong_tren_k(E);
		  		 		getch();
		        		break;
					case 14: thongke_hd_giatien_tren_k(E);
		  		 		getch();
		        		break;
					case 15: thongke_hd_tenkh(E);
		  		 		getch();
		        		break;
					case 16: HoaDon_NgayLap(E);
		  		 		getch();
		        		break;	
					case 17: sapxep_hd_ten(E);
						cout<<"Danh sach sau khi sap xep la: "<<endl;
						xuatDSHD(E);
		  		 		getch();
		        		break;
					case 18: 
						sua(E);
						break;									  
		   		default:
				     	printf("\nLua chon khong hop le. Nhap lai");
				     	break;
		 		}

			}while(k!=0);
		}
	}
}
int main(){
	MatHang x;
	NodeMH *p;
	DLishMH Q;
	Initializer(Q);

	NhanVien y;
	NodeNV *q;
	DLishNV H;
	InitializerNV(H);
	
	cout<<"Bat dau lam viec"<<endl;	
	menu();

  	cout<<"\n---------------END----------------\n";
}
