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

void printLeftNode(Node* root)
{
    if(root==NULL)
        return;

    if(root->left==NULL && root->right==NULL)
        return;

    cout<<root->data<<" ";
    
    if(root->left)
        printLeftNode(root->left);
    else
        printLeftNode(root->right);
    return;
}

void printLeafNode(Node* root)
{
    if(root==NULL)
        return;

    if(root->left==NULL && root->right==NULL)
        cout<<root->data<<" ";

    printLeafNode(root->left);
    printLeafNode(root->right);
    return;
}

void printRightNode(Node* root)
{
    if(root==NULL)
        return;

    if(root->left==NULL && root->right==NULL)
        return;
    
    if(root->right)
        printRightNode(root->right);
    else
        printRightNode(root->left);
    
    cout<<root->data<<" ";
    return;
}

void boundaryTraversal(Node* root)
{
    if(root ==NULL)
        return;

    cout<<root->data<<" ";

    if(root->left==NULL && root->right==NULL)
        return;

    printLeftNode(root->left);
    printLeafNode(root);
    printRightNode(root->right);
}

int main()
{
    Node* root = NULL;
    root = buildTree();

    boundaryTraversal(root);
    return 0;
}