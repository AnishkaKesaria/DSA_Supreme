#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    if(n==0 || n==1)
        return 1;

    int ans = climbStairs(n-1) + climbStairs(n-2);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<climbStairs(n);
    return 0;
}