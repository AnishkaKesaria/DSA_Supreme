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

void bottomView(Node* root)
{
    if(root==NULL)
        return;

    map<int,int> bottomNode;

    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));

    while(!q.empty())
    {
        pair<Node*, int> p = q.front();
        q.pop();

        Node* frontNode = p.first;
        int d = p.second;

        bottomNode[d] = frontNode->data;

        if(frontNode->left)
            q.push(make_pair(frontNode->left,d-1));
        if(frontNode->right)
            q.push(make_pair(frontNode->right, d+1));
    }

    for(auto i: bottomNode)
        cout<<i.first<<"->"<<i.second;
    return;
}

int main()
{
    Node* root = NULL;
    root = buildTree();

    bottomView(root);
}