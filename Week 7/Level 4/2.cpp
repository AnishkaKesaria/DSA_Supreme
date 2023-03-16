#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y, int z)
{
    if(n==0)
        return 0;
    if(n<0)
        return INT_MIN;

    int a = 0,b=0,c=0;
    a = solve(n-x,x,y,z)+1;
    b = solve(n-y,x,y,z)+1;
    c = solve(n-z,x,y,z)+1;

    int ans = max(a,max(b,c));
    return ans;
}

int main()
{
    int n=7, x=5, y=2, z=2;

    int ans = solve(n,x,y,z);
    cout<<ans;
}