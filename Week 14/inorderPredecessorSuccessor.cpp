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

Node* insertIntoBST(Node* root, int data)
{
   //firstelement to insert
   if(root==NULL)
   {
      root = new Node(data);
      return root;
   }

   if(root->data > data)
      root->left = insertIntoBST(root->left,data);
   else
      root->right = insertIntoBST(root->right, data);

   return root;
}

 void takeInput(Node* &root)
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

Node* findNodeInBST(Node* root, int target)
{
   //BASE CASE
   if(root==NULL)
       return NULL;
   if(root->data == target)
       return root;
   if(root->data > target)
       return findNodeInBST(root->left, target);
   else
       return findNodeInBST(root->right, target);
}

int findMin(Node* root)
{
    if(root==NULL)
        return -1;

    Node* temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int findMax(Node* root)
{
    if(root==NULL)
        return -1;

    Node* temp = root;

    while(temp->right!=NULL)
    {
        temp = temp->right;
    }
    return temp->data;
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

        if(temp==NULL && q.empty())
            return;

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
    return;
}

// Node* deleteNode(Node* root, int target)
// {
//     cout<<"entered";
//     if(root==NULL)
//         return NULL;

//     Node* temp = findNodeInBST(root, target);
//     if(temp->left==NULL && temp->right==NULL)
//     {
//        delete temp;
//        return NULL;
//     }
//     else if(temp->left==NULL)
//     {
//        Node* child = temp->right;
//        delete temp;
//        return child;
//     }
//     else if(temp->right==NULL)
//     {
//        Node* child = temp->left;
//        delete temp;
//        return child;
//     }
//     else
//     {
//         int MaxVal = findMax(temp->left);
//         temp->data = MaxVal;
//         temp->left = deleteNode(temp->left, MaxVal);
//         return root;
//     }
// }

Node* deleteNode(Node* root, int target)
{
    if(root==NULL)
        return NULL;

    if(root->data == target)
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if(root->left==NULL)
        {
            Node* child = root->right;
            delete root;
            return child;
        }
        else if(root->right==NULL)
        {
            Node* child = root->left;
            delete root;
            return child;
        }
        else
        {
            int maxVal = findMax(root->left);
            root->data = maxVal;
            root->left = deleteNode(root->left, maxVal);
            return root;
        }
    }

    else if(root->data < target)
        root->right = deleteNode(root->right, target);

    else if(root->data > target)
        root->left = deleteNode(root->left, target);

    return root;
}

 int main()
 {
    Node* root = NULL;
    cout<<"Enter the data for node"<<endl;
    takeInput(root);
    int target;
    cout<<"Enter node to delete: "<<endl;
    cin>>target;
    cout<<"BST before deletion:"<<endl;
    levelOderTraversal(root);
    cout<<"Printed";
    root = deleteNode(root, target);
    cout<<"BST after deletion:"<<endl;
    levelOderTraversal(root);
    return 0;
 }