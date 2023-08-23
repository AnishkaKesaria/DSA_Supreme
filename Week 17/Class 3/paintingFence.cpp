#include <bits/stdc++.h>
using namespace std;

long long countWays(int n, int k){
        // code here
        long long mod = 1000000007;
        
        if(n==1)
            return k;
            
        if(n==2)
            return (k + k*(k-1));
            
        long long ans = ((countWays(n-1,k)+countWays(n-2,k))*(k-1)) % mod;
        return ans;
}