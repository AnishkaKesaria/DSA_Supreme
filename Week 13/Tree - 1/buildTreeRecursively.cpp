#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this-> data = data;
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

int main()
{
    Node* root = NULL;
    root = buildTree();
    return 0;
}