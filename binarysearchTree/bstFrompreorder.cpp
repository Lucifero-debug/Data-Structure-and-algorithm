#include <iostream>
using namespace std;
#include <vector>

class BinaryTreeNode {
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

BinaryTreeNode*solve(vector<int> &preorder,int mini,int maxi,int &i){
    if(i>=preorder.size()){
        return NULL;
    }
    if(preorder[i]<mini || preorder[i]>maxi){
        return NULL;
    }
    BinaryTreeNode* root=new BinaryTreeNode(preorder[i++]);
    root->left=solve(preorder,mini,root->data,i);
    root->right=solve(preorder,root->data,maxi,i);
    return root;
}

BinaryTreeNode* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int i=0;
   return solve(preorder,mini,maxi,i);
}

int main(){
    return 0;
}