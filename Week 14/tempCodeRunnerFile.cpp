Node* deleteNode(Node* root, int target)
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