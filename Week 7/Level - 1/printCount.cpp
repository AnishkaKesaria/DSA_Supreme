#include <bits/stdc++.h>
using namespace std;

void printCount(int n)
{
    if(n==0)
        return;

    cout<<n<<" ";
    printCount(n-1);
    return;
}

int main()
{
    int n;
    cin>>n;
    printCount(n);
    return 0;
}