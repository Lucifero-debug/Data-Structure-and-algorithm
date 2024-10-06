#include <iostream>
using namespace std;
#include <vector>

class TreeNode {
    public : 
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

void inOrder(TreeNode *root, vector<int> &ans) {
  if (root == NULL)
    return;
  inOrder(root->left, ans);
  ans.push_back(root->data);
  inOrder(root->right, ans);
}

TreeNode* flatten(TreeNode* root)
{
    // Write your code here
    //step 1:-inorder m ans store
    //step 2:-link list create
    //step 3:-last wli node ka left right null

    //step 1
    vector<int>ans;
    inOrder(root,ans);
    //step 2
    int n=ans.size();
    TreeNode* newRoot=new TreeNode(ans[0]);
    TreeNode* curr=newRoot;
    for(int i=1;i<n;i++){
        TreeNode* temp=new TreeNode(ans[i]);
        curr->right=temp;
        curr->left=NULL;
        curr=curr->right;
    }
    curr->left=NULL;
    curr->right=NULL;
    return newRoot;
};

int main(){
    return 0;
}