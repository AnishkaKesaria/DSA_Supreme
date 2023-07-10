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

 int main()
 {
    Node* root = NULL;
    cout<<"Enter the data for node"<<endl;
    takeInput(root);
    cout<<"Printing tree:"<<endl;
    levelOderTraversal(root);
    return 0;
 }