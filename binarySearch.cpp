#include <bits/stdc++.h>
using namespace std;
void nhapMang(vector<int> &a,int &n)
{
    cout<<"Nhap so phan tu mang: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int b;
        cin>>b;
        a.push_back(b);
    }
}
int binarySearch(vector<int> &a,int n,int x)
{
    int left=0,right=n-1,middle;
    do
    {
        middle=(left+right)/2;
        if(a[middle]==x)
            break;
        if(a[middle]>x)
            right = middle-1;
        else
            left = middle+1;
    }
    while(left<=right);
    if(left<=right) return middle;
    else return -1;
}
int main()
{
    freopen("INPUT.txt","r",stdin);
    freopen("OUTPUT.txt","w",stdout);
    vector<int> a;
    int n;
    nhapMang(a,n);
    sort(a.begin(),a.end());
    cout<<"Mang da nhap la: ";
    for(auto i:a) cout<<i<<" ";
    int x;
    cout<<"\nNhap phan tu x can tim: ";
    cin>>x;
    if(binarySearch(a,n,x)!=-1)
    {
        cout<<"Vi tri tim thay x la: "<<binarySearch(a,n,x);
    }
    else
    {
        cout<<"Khong tim thay x";
    }
}
