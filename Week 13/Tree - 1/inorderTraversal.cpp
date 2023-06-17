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

void inOrder(Node* root)
{
    if(root==NULL)
        return;

    inOrder(root->left);
        //cout<<root->left->data<<" ";

    cout<<root->data<<" ";

    inOrder(root->right);
        //cout<<root->right->data<<" ";
}

int main()
{
    Node* root = NULL;
    root = buildTree();

    inOrder(root);

    return 0;
}