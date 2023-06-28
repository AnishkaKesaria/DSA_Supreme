#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree()
{
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data==-1)
        return NULL;

    //A - Root
    Node* root = new Node(data);

    //B - left child - recursive call
    cout<<"Enter data for left child of "<<data<<" :"<<endl;
    root->left = buildTree();

    //C - right child - recursive call;
    cout<<"Enter data for right child of "<<data<<" :"<<endl;
    root->right = buildTree();

    return root;
}


void leftViewNode(Node* root, int d, map<int,int> &m)
{
    if(root==NULL)
        return;
        
    if(m.find(d) == m.end())
        m[d] = root->data;
        
    leftViewNode(root->left, d+1, m);
    leftViewNode(root->right, d+1, m);
}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   
   map<int, int> m;
   int d = 0;
   leftViewNode(root, d, m);
   for(auto i: m)
        ans.push_back(i.second);
        
    return ans;
}