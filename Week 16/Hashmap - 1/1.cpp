#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string,int> m;
    pair<string,int> p = make_pair("Scorpio", 9);
    m.insert(p);
    pair<string,int> p2("alto", 2);
    m.insert(p2);
    m["fortuner"] = 10;

    cout<<m.at("alto")<<endl;
    cout<<m.count("Innova")<<endl;
    if(m.find("fortuner")!=m.end())
        cout<<"found"<<endl;
    else
        cout<<"Not found"<<endl;

    cout<<m.size()<<endl;
    cout<<m["hummer"]<<endl;
    cout<<m.size()<<endl;

    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}