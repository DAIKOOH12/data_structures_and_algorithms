#include <bits/stdc++.h>
using namespace std;
void nhapMang(vector<int> &a,int &n)
{
    cout<<"Nhap so phan tu mang: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int b;cin>>b;
        a.push_back(b);
    }
}
bool lineSearch(vector<int> &a,int n)
{
    cout<<"Nhap phan tu x: ";
    int x;cin>>x;
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
            return true;
    }
    return false;
}
int main()
{
    vector<int> a;
    int n;
    nhapMang(a,n);
    if(lineSearch(a,n))
    {
        cout<<"Co phan tu x";
    }
    else
    {
        cout<<"Khong ton tai phan tu x";
    }

}
