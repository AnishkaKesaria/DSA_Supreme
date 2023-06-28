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

void printTopView(Node* root)
{
    if(root==NULL)
        return;

    //create a map for storing horizontal distance ->Topnode->data
    //Distance -> node ka data
    map<int,int> topNode;

    //levelOrder
    queue<pair<Node*, int>> q;
    q.push(make_pair(root,0));
    
    while(!q.empty())
    {
        pair<Node*, int> temp = q.front();

        q.pop();

        Node* frontNode = temp.first;
        int d = temp.second;

        //check if d exists in map called topNode
        if(topNode.find(d)==topNode.end())
        {
            topNode[d] = frontNode->data;
        }
        if(frontNode->left)
            q.push(make_pair(frontNode->left,d-1));
        if(frontNode->right)
            q.push(make_pair(frontNode->right, d+1));
    }

    cout<<"Printing ans:";
    for(auto i: topNode)
        cout<<i.first<<" ->"<<i.second<<endl;

    vector<int> ans;

    cout<<"Printing vector:" <<endl;
    map<int,int>:: iterator it = topNode.begin();
    // while (it != topNode.end())
    //     ans.push_back(it->second);

    for (auto i = topNode.begin(); i != topNode.end(); i++)
        ans.push_back(i->second);

    int n = ans.size();
    for(int i=0; i<n; i++)
        cout<<ans[i]<<" ";

    return;    
}

int main()
{
    Node* root = NULL;
    root = buildTree();

    printTopView(root);

    return 0;
}