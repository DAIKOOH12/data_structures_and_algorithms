#include <bits/stdc++.h>
using namespace std;
void nhapMang(vector<int> &a,int &n)
{
    cout<<"Nhap so luong phan tu: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int b;
        cin>>b;
        a.push_back(b);
    }
}
void quickSort(vector<int> &a,int left,int right)
{
    int i,j,x;
    x=a[(left+right)/2];
    i=left,j=right;
    do
    {
        while(a[i]<x) i++;
        while(a[j]>x) j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    while(i<=j);
    if(left<j) quickSort(a,left,j);
    if(i<right) quickSort(a,i,right);
}
int main()
{
    freopen("INPUT.txt","r",stdin);
    freopen("OUTPUT.txt","w",stdout);
    vector<int> a;
    int n;
    nhapMang(a,n);
    quickSort(a,0,a.size()-1);
    cout<<"\nMang sau khi sort: ";
    for(auto i:a) cout<<i<<" ";
}
