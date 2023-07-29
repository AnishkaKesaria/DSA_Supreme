#include <bits/stdc++.h>
using namespace std;


int main()
{
    string s = "thiruvananthapuram";
    map<char,int> m;
    for(int i=0; i<s.length(); i++)
        m[s[i]]++;

    for(auto i: m)
        cout<<i.first<<" "<<i.second<<endl;

    return 0;
}