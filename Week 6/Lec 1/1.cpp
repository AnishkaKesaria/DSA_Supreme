#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 5;
    int b = 5;
    cout<<a<<endl;
    cout<<"Address of a :"<<&a<<endl;
    cout<<"Address of b :"<<&b<<endl;

    int* p = &a;
    cout<<"Value of p: "<<p<<endl;
    cout<<"Value p is pointing to: "<<*p<<endl;
    cout<<"Address of p: "<<&p<<endl;

    int x = 10;
    char y = 'b';
    double z = 1.03;

    int* q = &x;
    char* r = &y;
    double* s = &z;

    cout<<"Size of q: "<<sizeof(q)<<endl;
    cout<<"Size of r: "<<sizeof(r)<<endl;
    cout<<"Size of s: "<<sizeof(s)<<endl;

    int *ptr;
    cout<<*ptr<<endl;

    int * dtr = 0;
    cout<<*dtr<<endl;
    return 0;
}