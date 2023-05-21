#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    //insert
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    //remove
    st.pop();
    //check element on top
    cout<<"ELement at top: "<<st.top()<<endl;
    //size of stack
    cout<<"Size of stack: "<<st.size()<<endl;
    // is empty
    if(st.empty())
        cout<<"Stack is empty";
    else
        cout<<"Stack isn't empty";
    cout<<endl;
    return 0;
}