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
void bubbleSort(vector<int> &a,int n)
{
    for(int i=0;i<n;i++)
        for(int j=n-1;j>i;j--)
            if(a[i]>a[j])
                swap(a[i],a[j]);

}
int main()
{
    freopen("INPUT.txt","r",stdin);
    freopen("OUTPUT.txt","w",stdout);
    vector<int> a;
    int n;
    nhapMang(a,n);
    bubbleSort(a,n);
    cout<<"Mang sau khi sap xep la: ";
    for(auto i:a) cout<<i<<" ";
}
