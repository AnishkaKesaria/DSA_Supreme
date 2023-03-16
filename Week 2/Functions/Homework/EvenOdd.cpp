#include <bits/stdc++.h>
using namespace std;

bool Odd(int n)
{
    if(n%2==1)
        return 1;
    return 0;
}

int main()
{
    int n;
    cin>>n;
    if(Odd(n))
        cout<<"The number is odd";
    else
        cout<<"The number is even";
    return 0;
}