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

void levelOderTraversal(Node* &root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp==NULL &&!q.empty())
        {
            q.push(NULL);
            cout<<endl;
            continue;
        }

        cout<<temp->data<<" ";
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

int main()
{
    Node* root = NULL;
    root = buildTree();

    levelOderTraversal(root);

    return 0;
}