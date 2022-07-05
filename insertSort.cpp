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
void insertSort(vector<int> &a,int n)
{
    int i, key, j;
    //4 2 6 1 7
    //2 4 6 1 7
    for (i = 1; i < n; i++)
    {
        //i=1,i=2,i=3,i=4
        key = a[i];//2 4 6 1
        j = i-1;//0 1 2 3

        /* Di chuyển các phần tử có giá trị lớn hơn giá trị
        key về sau một vị trí so với vị trí ban đầu
        của nó */
        while (j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            //2 4 6 1 7
            //2 4 1 6 7
            //2 1 4 6 7
            //1 2 4 6 7
            j = j-1;// 2 1 0
        }
        a[j+1] = key;//a[0]=2,a[1]=4
    }
}
int main()
{
    freopen("INPUT.txt","r",stdin);
    freopen("OUTPUT.txt","w",stdout);
    vector<int> a;
    int n;
    nhapMang(a,n);
    insertSort(a,n);
    cout<<"Mang sau khi sap xep la: ";
    for(auto i:a) cout<<i<<" ";
}
