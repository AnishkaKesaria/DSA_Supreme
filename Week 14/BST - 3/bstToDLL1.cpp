// TC - O(n)
// SC - O(H) 
// In worst case - O(n)


#include <bits/stdc++.h>
using namespace std;

class Node
{
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

Node* insertIntoBST(Node* root, int data)
{
    if(root==NULL)
    {
        Node* root = new Node(data);
        return root;
    }

    if(root->data > data)
        root->left = insertIntoBST(root->left, data);
    else
        root->right = insertIntoBST(root->right, data);

    return root;
}

void takeInput(Node* root)
{
    int data;
    cin>>data;

    while(data!=-1)
    {
        root = insertIntoBST(root, data);
        cin>>data;
    }
    return;
}

void toDLL(Node* root, Node* head)
{
    if(root==NULL)
        return;

    toDLL(root->right, head);
    root->right = head;

    if(head!=NULL)
        head->left = root;

    head = root;
    toDLL(root->left, head);
    return;
}

int main()
{
    Node* root = NULL;
    takeInput(root);
    Node* head = NULL;
    toDLL(root, head);
}