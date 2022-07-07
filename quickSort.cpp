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
    //4 8 1 23 21 19 3
    x=a[(left+right)/2];//x=23
    i=left,j=right;//i=0,j=7
    do
    {
        while(a[i]<x) i++;
        while(a[j]>x) j--;
        //i=3,j=7
        //i=7,j=6
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
        //4 8 1 3 21 19 23
        //i=4,j=6
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
