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

  void inOrder(BinaryTreeNode* root,int &i,int k,int &ans){
        if(root==NULL) return;
        inOrder(root->left,i,k,ans);
        if(i==k){
            return;
        }
        if(++i==k){
            ans=root->data;
            return;
        }
        inOrder(root->right,i,k,ans);
    }

int kthSmallest(BinaryTreeNode* root, int k) {
    // Write your code here.
    int ans=-1;
    int i=0;
    inOrder(root,i,k,ans);
    return ans;
}

int main(){
    return 0;
}