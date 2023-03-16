#include <bits/stdc++.h>
using namespace std;

float toMiles(float km)
{
    return(km/1.6);
}

int main()
{
    float km;
    cin>>km;
    cout<<toMiles(km);
    return 0;
}