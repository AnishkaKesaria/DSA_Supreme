#include <bits/stdc++.h>
using namespace std;

void printPermutation(string &str, int i)
{
    //base case
    if(i>=str.length())
    {
        cout<<str<<endl;
        return;
    }

    for(int j=i; j<str.length(); j++)
    {
        swap(str[i],str[j]);
        printPermutation(str, i+1);
        //backtracking
        swap(str[i],str[j]);
        // Agar by refrence nhi pass kiye hote string ko toh upar wale ke bina chal jaata
    }
}

int main()
{
    string str = "abb";
    int i=0;
    printPermutation(str,i);
    return 0;
}