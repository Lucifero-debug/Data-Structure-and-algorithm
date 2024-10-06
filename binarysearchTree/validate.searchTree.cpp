#include <iostream>
using namespace std;

 class BinaryTreeNode 
    {
    public : 
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

bool validateHelper(BinaryTreeNode  *root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data<=max && root->data>=min){
    bool left=validateHelper(root->left,INT_MIN, root->data);
    bool right=validateHelper(root->right, root->data, INT_MAX);
    return left&&right;
    }
    else
        return false;
    
 
  
}
bool validateBST(BinaryTreeNode *root) {
return validateHelper(root,INT_MIN,INT_MAX);
   }


int main(){

    return 0;
}