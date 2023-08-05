#include <bits/stdc++.h>
using namespace std;

bool isPresent(string &s, int n, char &k)
{
    if(n<0)
        return false;
    
    if(s[n-1]==k)
        return true;
    
    // isPresent(s,n-1,k);
    return isPresent(s,n-1,k);
}

int main()
{
    string str =  "lovebabbar";
    int n = str.length();
    char key = 'm';
    bool ans = isPresent(str, n, key);
    cout<<ans<<endl;
    
}