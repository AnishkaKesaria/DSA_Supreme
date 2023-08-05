#include <bits/stdc++.h>
using namespace std;

void printSubsequences(string str, string output, int i)
{
    if(i>=str.length())
    {
        cout<<output<<endl;
        return;
    }

    //inclusion 
    printSubsequences(str, output+str[i], i+1);

    //exclusion
    printSubsequences(str, output, i+1);
    
    return;
}

int main()
{
    string str = "abcd";
    string output = "";
    int i=0;
    printSubsequences(str, output, i);
    return 0;
}