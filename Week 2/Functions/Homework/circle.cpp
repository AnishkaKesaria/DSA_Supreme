#include <bits/stdc++.h>
using namespace std;

float carea (float r)
{
    float area = (3.14)*r*r;
    return area;
}

int main()
{
    float r;
    cin>>r;
    float area = carea(r);
    cout<<area;
    return 0;
}