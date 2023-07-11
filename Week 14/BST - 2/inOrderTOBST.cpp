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
        this->left = NULL;
        this->right = NULL;
    }
};

Node* inorderToBST(vector<int> inorder, int s, int e)
{
    if(s>e)
        return NULL;

    int mid = s+(e-s)/2;

    int element = inorder[mid];
    Node* root = new Node(element);

    root->left = inorderToBST(inorder, s, mid-1);
    root->right = inorderToBST(inorder, mid+1, e);

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
    int n;
    cin>>n;
    vector<int> inorder(n,0);
    for(int i=0; i<n; i++)
        cin>>inorder[i];

    Node* root = NULL;
    root = inorderToBST(inorder, 0, n-1);
    levelOderTraversal(root);
    return 0;
}