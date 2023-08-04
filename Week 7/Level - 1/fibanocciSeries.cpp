#include <bits/stdc++.h>
using namespace std;

int fibonocci(int n)
{
    if(n==0 || n==1)
        return n;

    return (fibonocci(n-1)+fibonocci(n-2));
}

int main()
{
    int n;
    cin>>n;
    cout<<fibonocci(n);
    return 0;
}