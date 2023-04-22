#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 10;
    int*p = &a;
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&p<<endl;
    cout<<*p*2<<endl;
    cout<<(*p)++<<endl;
    cout<<++(*p)<<endl;
    a = a+1;
    cout<<a<<endl;
    *p = *p+2;
    cout<<*p<<endl;
    *p = *p*2;
    cout<<*p<<endl;
    *p = *p/2;
    cout<<*p<<endl;
    return 0;
}