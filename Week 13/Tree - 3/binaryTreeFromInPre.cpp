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

int findPos(int arr[], int n, int element)
{
    for(int i=0; i<n; i++)
    {
        if(element == arr[i])
            return i;
    }
    return -1;
}

Node* buildTreeFromPreOrderInorder(int inorder[], int preorder[], int size, int &preIndex, int inOrderStart, int inOrderEnd)
{
    if(preIndex >= size || inOrderStart>inOrderEnd)
        return NULL;

    //Step A
    int element = preorder[preIndex];
    preIndex++;

    Node* root = new Node(element);
    int pos = findPos(inorder, size, element);
    root->left = buildTreeFromPreOrderInorder(inorder, preorder, size, preIndex, inOrderStart, pos-1);
    root->right = buildTreeFromPreOrderInorder(inorder, preorder, size, preIndex, pos+1, inOrderEnd);

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

// void showtree(Node* root)
// {
//     if(root==NULL)
//         return;

//     cout<<"Curr Node: "<<root->data<<endl;
//     cout<<"Left child of "<<root->data<<endl;
//     showtree(root->left);
//     cout<<"Right child of "<<root->data<<endl;
//     showtree(root->right);
//     return;
// }

Node* buildTree()
{
    int data;
    cout<<"Enter data: "<<endl;
    cin>>data;

    if(data==-1)
        return NULL;
    
    Node* root = new Node(data);
    cout<<"Enter left child of "<<data<<": "<<endl;
    root->left = buildTree();
    cout<<"Enter right child of "<<data<<": "<<endl;
    root->right = buildTree();

    return root;
}

int main()
{
    int size;
    cout<<"Enter size: "<<endl;
    cin>>size;
    int *inOrder = new int[size];
    for(int i=0; i<size; i++)
        cin>>inOrder[i];
    int *preOrder = new int[size];
    for(int i=0; i<size; i++)
        cin>>preOrder[i];

    Node* root = NULL;

    int preIndex = 0;
    root = buildTreeFromPreOrderInorder(inOrder, preOrder, size, preIndex, 0, size-1);
    levelOderTraversal(root);

    return 0;
}