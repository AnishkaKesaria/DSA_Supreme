#include <bits/stdc++.h>
using namespace std;

void nonRepeatingChar(string str)
{
    vector<int> freq(26,0);
    queue<char> q;

    string ans="";

    for(int i=0; i<str.length(); i++)
    {
        char ch = str[i];

        //increment freq

        freq[ch-'a']++;
        q.push(ch);

        //finding ans

        while(freq[q.front() - 'a']!=1 && (!q.empty()))
        {
            q.pop();
        }

        //adding ans to ans

        if(q.empty())
            ans += '#';
        else
            ans += q.front();
    }

    cout<<ans;
    return;
}

int main()
{
    string str;
    cin>>str;
    nonRepeatingChar(str);
    return 0;
}