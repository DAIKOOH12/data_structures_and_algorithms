#include <bits/stdc++.h>
using namespace std;
bool kiemTraSoNguyenTo(int a)
{
    //Hello my friend
    cout<<"Kiem tra so nguyen to\n";
    if(a==0||a==1) return false;
    int i=2;
    while(i*i<=a)
    {
        if(a%i==0) return false;
        i++;
    }
    return true;
}
int main()
{
    int a;
    cin>>a;
    if(kiemTraSoNguyenTo(a))
    {
        cout<<"a la so nguyen to";
    }
    else
    {
        cout<<"a khong la so nguyen to";
    }
}
