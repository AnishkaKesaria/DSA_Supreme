#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[4] = {12,14,16,18};
    cout<<arr<<endl;
    cout<<arr[0]<<endl;
    cout<<&arr<<endl;
    cout<<&arr[0]<<endl;
    cout<<*arr<<endl;
    cout<<*(arr+2)<<endl;

    cout<<0[arr]<<endl;
    cout<<arr[0]<<endl;

    int *p = arr;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<*p<<endl;
    return 0;
}