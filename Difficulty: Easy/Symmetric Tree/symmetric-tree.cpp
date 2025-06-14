/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
 public:
  bool isMirror(Node*l,Node* r){
        if( l== NULL &&  r== NULL){
            return true;
        }
        if( l== NULL ||  r== NULL){
            return false;
        }
        if((l->data==r->data) && isMirror(l->left, r->right) && isMirror(l->right, r->left)){
            return true;
        }
        return false;
        
        
    }
    bool isSymmetric(Node* root) {
        // Code here
        if(!root)
        return false;
       
        return isMirror(root->left, root->right);
        
    }
};