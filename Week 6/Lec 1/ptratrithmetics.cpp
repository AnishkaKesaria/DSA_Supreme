#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 5;
    int* p = &a;
    cout<<p<<endl;
    *p = *p+1;
    p = p+1;
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<a<<endl;
    *p = *p+1;
    cout<<*p<<endl;
    cout<<a<<endl;
    return 0;
}