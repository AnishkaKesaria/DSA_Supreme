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

 int main()
 {
    Node* root = NULL;
    cout<<"Enter the data for node"<<endl;
    takeInput(root);
    cout<<"Minimum element is: "<<findMin(root)<<endl;
    cout<<"Maximum element is: "<<findMax(root)<<endl;
    return 0;
 }