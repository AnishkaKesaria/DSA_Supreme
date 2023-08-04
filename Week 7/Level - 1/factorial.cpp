#include <bits/stdc++.h>
using namespace std;

int findFact(int n)
{
    if(n==1)
        return 1;

    return (n*findFact(n-1));
}

int main()
{
    int n;
    cin>>n;
    cout<<findFact(n);
    return 0;
}