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
    cout<<"Enter data:";
    cin>>data;

    if(data==-1)
        return NULL;

    //A - create node
    Node* root = new Node(data);

    //B - Left child
    cout<<"Enter left child of "<<data<<":"<<endl;
    root->left = buildTree();

    //C - Right child
    cout<<"Enter right child of "<<data<<":"<<endl;
    root->left = buildTree();
    return root;
}

int maxDepth(Node* root)
{
    if(root==NULL)
        return 0;

    int ans = max(maxDepth(root->left), maxDepth(root->right)) + 1;

    return ans;
}

int main()
{
    Node* root = NULL;
    root = buildTree();
    cout<<maxDepth(root);

    return 0;
}