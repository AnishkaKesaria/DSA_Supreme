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

Node* buildTreeFromPreOrderInorder(int inorder[], int postorder[], int size, int &postIndex, int inOrderStart, int inOrderEnd)
{
    if(postIndex <0 || inOrderStart>inOrderEnd)
        return NULL;

    //Step A
    int element = postorder[postIndex];
    postIndex--;

    Node* root = new Node(element);
    int pos = findPos(inorder, size, element);
    
    root->right = buildTreeFromPreOrderInorder(inorder, postorder, size, postIndex, pos+1, inOrderEnd);
    root->left = buildTreeFromPreOrderInorder(inorder, postorder, size, postIndex, inOrderStart, pos-1);

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
    int *postOrder = new int[size];
    for(int i=0; i<size; i++)
        cin>>postOrder[i];

    Node* root = NULL;

    int postIndex = size-1;
    root = buildTreeFromPreOrderInorder(inOrder, postOrder, size, postIndex, 0, size-1);
    levelOderTraversal(root);

    return 0;
}