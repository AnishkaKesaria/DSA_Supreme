//Division Method

#include <bits/stdc++.h>
using namespace std;

int decimalToBinary(int n)
{
    int binaryNumber = 0;
    int i=0;
    while(n>0)
    {
        int bit = n%2;
        binaryNumber += pow(10,i)*bit;
        n/=2;
        i++;
    }
    return binaryNumber;
}


int main()
{
    int n;
    cin>>n;
    int binary = decimalToBinary(n);
    cout<<binary<<endl;
    return 0;
}